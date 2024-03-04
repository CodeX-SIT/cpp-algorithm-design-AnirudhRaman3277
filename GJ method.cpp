#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows and columns (n): ";
    cin >> n;

    // Initialize a vector of vectors to store the coefficients matrix
    vector<vector<int>> coefft(n, vector<int>(n));

    // Input coefficients matrix
    cout << "Enter the elements of the coefficients matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> coefft[i][j];
        }
    }

    // Initialize a vector to store the values of the unknowns
    vector<int> D_mat(n);

    // Input values of the unknowns
    cout << "Enter the values of the unknowns:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> D_mat[i];
    }

    // Set up matrix according to problem statement
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++) {
        vector<int> row = coefft[i];
        row.push_back(D_mat[i]);
        matrix.push_back(row);
    }

    // GJ Elimination
    int D_len = D_mat.size();
    for (int i = 0; i < D_len; i++) {
        int finalrow = i;
        for (int j = i + 1; j < D_len; j++) {
            if (abs(coefft[j][i]) > abs(coefft[finalrow][i])) {
                finalrow = j;
            }
        }
        swap(matrix[i], matrix[finalrow]);

        // Diagonal coefficients to 1
        double divisor = matrix[i][i];
        for (int j = i; j <= D_len; j++) {
            matrix[i][j] = matrix[i][j] / divisor;
        }

        // Other coefficients to 0
        for (int j = 0; j < D_len; j++) {
            if (i != j) {
                double factor = matrix[j][i];
                for (int k = i; k <= D_len; k++) {
                    matrix[j][k] = matrix[j][k] - (factor * matrix[i][k]);
                }
            }
        }
    }

    // Updated D column matrix
    vector<int> final_D_MAT;
    for (int i = 0; i < D_len; i++) {
        final_D_MAT.push_back(matrix[i][D_len]);
    }

    // Output the final D column matrix
    cout << "The final D column matrix is:" << endl;
    for (int i = 0; i < D_len; i++) {
        cout << final_D_MAT[i] << " ";
    }
    cout << endl;

    return 0;
}

