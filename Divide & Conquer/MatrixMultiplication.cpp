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
    int C11[10][10], C12[10][10], C21[10][10], C22[10][10];
    
}
