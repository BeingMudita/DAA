//Matrix multiplication using divide & conquer
#include <bits/stdc++.h>
using namespace std;

void add(int A[10][10], int B[10][10], int C[10][10], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void MM(int A[10][10], int B[10][10], int C[10][10], int n){
    if(n==1){
        C[0][0] = A[0][0] * B[0][0];
    }
    int k = n/2;
    //Create temporary matrices
    int A11[10][10], A12[10][10], A21[10][10], A22[10][10];
    int B11[10][10], B12[10][10], B21[10][10], B22[10][10];
    int C11[10][10] ={0}, C12[10][10]={0}, C21[10][10]={0}, C22[10][10]={0};

    int M1[10][10] ={0}, M2[10][10]={0};

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }
    }
    MM(A11, B11, M1, k); //A11*B11
    MM(A12, B21, M2, k); //A12*B21
    add(M1, M2, C11, k); //C11 = M1 + M2

    MM(A11, B12, M1, k); //A11*B12
    MM(A12, B22, M2, k); //A12*B22  
    add(M1, M2, C12, k); //C12 = M1 + M2
}
