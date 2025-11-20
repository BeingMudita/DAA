#include <bits/stdc++.h>
using namespace std;

// Function to add two matrices
void add(int A[10][10], int B[10][10], int C[10][10], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtract(int A[10][10], int B[10][10], int C[10][10], int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Recursive Strassen multiplication
void strassen(int A[10][10], int B[10][10], int C[10][10], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int A11[10][10], A12[10][10], A21[10][10], A22[10][10];
    int B11[10][10], B12[10][10], B21[10][10], B22[10][10];
    int C11[10][10], C12[10][10], C21[10][10], C22[10][10];
    int M1[10][10], M2[10][10], M3[10][10], M4[10][10], M5[10][10], M6[10][10], M7[10][10];
    int temp1[10][10], temp2[10][10];

    memset(C11, 0, sizeof(C11));
    memset(C12, 0, sizeof(C12));
    memset(C21, 0, sizeof(C21));
    memset(C22, 0, sizeof(C22));

    // Splitting matrices into 4 submatrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    add(A11, A22, temp1, k);
    add(B11, B22, temp2, k);
    strassen(temp1, temp2, M1, k);

    // M2 = (A21 + A22) * B11
    add(A21, A22, temp1, k);
    strassen(temp1, B11, M2, k);

    // M3 = A11 * (B12 - B22)
    subtract(B12, B22, temp1, k);
    strassen(A11, temp1, M3, k);

    // M4 = A22 * (B21 - B11)
    subtract(B21, B11, temp1, k);
    strassen(A22, temp1, M4, k);

    // M5 = (A11 + A12) * B22
    add(A11, A12, temp1, k);
    strassen(temp1, B22, M5, k);

    // M6 = (A21 - A11) * (B11 + B12)
    subtract(A21, A11, temp1, k);
    add(B11, B12, temp2, k);
    strassen(temp1, temp2, M6, k);

    // M7 = (A12 - A22) * (B21 + B22)
    subtract(A12, A22, temp1, k);
    add(B21, B22, temp2, k);
    strassen(temp1, temp2, M7, k);

    // Compute C11, C12, C21, C22
    // C11 = M1 + M4 - M5 + M7
    add(M1, M4, temp1, k);
    subtract(temp1, M5, temp2, k);
    add(temp2, M7, C11, k);

    // C12 = M3 + M5
    add(M3, M5, C12, k);

    // C21 = M2 + M4
    add(M2, M4, C21, k);

    // C22 = M1 - M2 + M3 + M6
    subtract(M1, M2, temp1, k);
    add(temp1, M3, temp2, k);
    add(temp2, M6, C22, k);

    // Combine results into C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Enter matrix size (power of 2): ";
    cin >> n;

    int A[10][10], B[10][10], C[10][10];
    cout << "Enter first matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter second matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    memset(C, 0, sizeof(C));
    strassen(A, B, C, n);

    cout << "Resultant matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
