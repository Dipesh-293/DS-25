#include <iostream>
using namespace std;

struct Triple {
    int row, col, val;
};

int main() {
    int rows, cols, nonZero;
    cout << "Enter rows, cols, non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    Triple A[100], B[100]; // Triplet representation
    A[0].row = rows;
    A[0].col = cols;
    A[0].val = nonZero;

    cout << "Enter triplets (row col value):\n";
    for (int i = 1; i <= nonZero; i++) {
        cin >> A[i].row >> A[i].col >> A[i].val;
    }

    // Transpose
    B[0].row = cols;
    B[0].col = rows;
    B[0].val = nonZero;

    int k = 1;
    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= nonZero; i++) {
            if (A[i].col == c) {
                B[k].row = A[i].col;
                B[k].col = A[i].row;
                B[k].val = A[i].val;
                k++;
            }
        }
    }

    cout << "\nTranspose in triplet form:\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << B[i].row << " " << B[i].col << " " << B[i].val << endl;
    }
    return 0;
}
