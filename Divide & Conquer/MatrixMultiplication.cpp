#include <bits/stdc++.h>
using namespace std;
void add(int A[10][10], int B[10][10], int C[10][10], int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            C[i][j]=A[i][j]+ B[i][j];
        }
    }
}
void multiply (int A[10][10], int B[10][10], int C[10][10], int n){
    if (n==1){
        C[0][0]=A[0][0]*B[0][0];
    }
    int k=n/2;
    int A11[10][10], A12[10][10], A21[10][10], A22[10][10];
    int B11[10][10], B12[10][10], B21[10][10], B22[10][10];
    int C11[10][10]={0}, C12[10][10]={0}, C21[10][10]={0}, C22[10][10]={0};
    int M1[10][10]={0}, M2[10][10]={0}, M3[10][10]={0}, M4[10][10]={0};
    for (int i=0;i<k;i++){
        for (int j=0;j<k;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+k];
            A21[i][j]=A[i+k][j];
            A22[i][j]=A[i+k][j+k];
            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+k];
            B21[i][j]=B[i+k][j];
            B22[i][j]=B[i+k][j+k];
        }
    }
    multiply(A11, B11, M1, k);
    multiply(A12, B21, M2, k);
    add(M1, M2, C11, k);

    multiply(A11, B12, M1, k);
    multiply(A12, B22, M2, k);
    add(M1, M2, C12, k);
    multiply(A21, B11, M1, k);
    multiply(A22, B21, M2, k);
    add(M1, M2, C21, k);

    multiply(A21, B12, M1, k);
    multiply(A22, B22, M2, k);
    add(M1, M2, C22, k);

    for (int i=0;i<k;i++){
        for (int j=0;j<k;j++){
            C[i][j]=C11[i][j];
            C[i][j+k]=C12[i][j];
            C[i+k][j]=C21[i][j];
            C[i+k][j+k]=C22[i][j];
        }
    }
}
void printmatrix(int M[10][10], int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int A[10][10], B[10][10], C[10][10]={0};
    int n, i, j;
    cout<<"Enter order of matrix (n x n): ";
    cin>>n;
    cout<<"Enter elements of matrix A: "<<endl;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    cout<<"Enter elements of matrix B: "<<endl;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            cin>>B[i][j];
        }
    }
    multiply(A, B, C, n);
    cout<<"Product of matrix A and B is: "<<endl;
    printmatrix(C, n);
    return 0;
}