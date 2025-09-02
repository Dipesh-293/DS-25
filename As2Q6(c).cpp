#include <iostream>
using namespace std;

struct Triplet {
    int row, col, val;
};

void multiplySparse(Triplet A[], Triplet B[], Triplet C[]) {
    if (A[0].col != B[0].row) {
        cout << "Multiplication not possible\n";
        return;
    }

    int rows = A[0].row, cols = B[0].col;
    C[0].row = rows;
    C[0].col = cols;
    C[0].val = 0;

    int k = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int x = 1; x <= A[0].val; x++) {
                if (A[x].row == i) {
                    for (int y = 1; y <= B[0].val; y++) {
                        if (B[y].col == j && B[y].row == A[x].col) {
                            sum += A[x].val * B[y].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                C[k].row = i;
                C[k].col = j;
                C[k].val = sum;
                k++;
            }
        }
    }
    C[0].val = k - 1;
}

int main() {
    Triplet A[4] = {
        {2, 2, 3}, // 2x2 matrix, 3 non-zeros
        {0, 0, 1},
        {0, 1, 2},
        {1, 0, 3}
    };

    Triplet B[3] = {
        {2, 2, 2}, // 2x2 matrix, 2 non-zeros
        {0, 1, 4},
        {1, 0, 5}
    };

    Triplet C[10];
    multiplySparse(A, B, C);

    cout << "Result of Multiplication in triplet form:\n";
    for (int i = 0; i <= C[0].val; i++) {
        cout << C[i].row << " " << C[i].col << " " << C[i].val << endl;
    }
    return 0;
}
