#include <iostream>
using namespace std;

struct Triple {
    int row, col, val;
};

int main() {
    int r, c, nz1, nz2;
    cout << "Enter rows, cols of matrices: ";
    cin >> r >> c;

    cout << "Enter number of non-zero elements in first matrix: ";
    cin >> nz1;
    Triple A[100];
    A[0] = {r, c, nz1};
    cout << "Enter triplets (row col value) for first matrix:\n";
    for (int i = 1; i <= nz1; i++) cin >> A[i].row >> A[i].col >> A[i].val;

    cout << "Enter number of non-zero elements in second matrix: ";
    cin >> nz2;
    Triple B[100];
    B[0] = {r, c, nz2};
    cout << "Enter triplets (row col value) for second matrix:\n";
    for (int i = 1; i <= nz2; i++) cin >> B[i].row >> B[i].col >> B[i].val;

    Triple C[200];
    C[0] = {r, c, 0};
    int i = 1, j = 1, k = 1;

    while (i <= nz1 && j <= nz2) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        } else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        } else {
            C[k] = A[i];
            C[k].val = A[i].val + B[j].val;
            if (C[k].val != 0) k++;
            i++; j++;
        }
    }
    while (i <= nz1) C[k++] = A[i++];
    while (j <= nz2) C[k++] = B[j++];

    C[0].val = k-1;

    cout << "\nResult of Addition in triplet form:\n";
    for (int x = 0; x < k; x++) {
        cout << C[x].row << " " << C[x].col << " " << C[x].val << endl;
    }
    return 0;
}
