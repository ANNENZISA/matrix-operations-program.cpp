#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

void displayMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

Matrix addMatrices(const Matrix& mat1, const Matrix& mat2) {
    Matrix result;
    for (size_t i = 0; i < mat1.size(); ++i) {
        vector<int> row;
        for (size_t j = 0; j < mat1[i].size(); ++j) {
            row.push_back(mat1[i][j] + mat2[i][j]);
        }
        result.push_back(row);
    }
    return result;
}

Matrix subtractMatrices(const Matrix& mat1, const Matrix& mat2) {
    Matrix result;
    for (size_t i = 0; i < mat1.size(); ++i) {
        vector<int> row;
        for (size_t j = 0; j < mat1[i].size(); ++j) {
            row.push_back(mat1[i][j] - mat2[i][j]);
        }
        result.push_back(row);
    }
    return result;
}

Matrix multiplyMatrices(const Matrix& mat1, const Matrix& mat2) {
    Matrix result(mat1.size(), vector<int>(mat2[0].size(), 0));

    for (size_t i = 0; i < mat1.size(); ++i) {
        for (size_t j = 0; j < mat2[0].size(); ++j) {
            for (size_t k = 0; k < mat1[0].size(); ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

Matrix transposeMatrix(const Matrix& mat) {
    Matrix result(mat[0].size(), vector<int>(mat.size(), 0));

    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[0].size(); ++j) {
            result[j][i] = mat[i][j];
        }
    }

    return result;
}

int main() {
    Matrix matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    cout << "Matrix 1:\n";
    displayMatrix(matrix1);

    cout << "\nMatrix 2:\n";
    displayMatrix(matrix2);

    cout << "\nMatrix Addition:\n";
    Matrix additionResult = addMatrices(matrix1, matrix2);
    displayMatrix(additionResult);

    cout << "\nMatrix Subtraction:\n";
    Matrix subtractionResult = subtractMatrices(matrix1, matrix2);
    displayMatrix(subtractionResult);

    cout << "\nMatrix Multiplication:\n";
    Matrix multiplicationResult = multiplyMatrices(matrix1, matrix2);
    displayMatrix(multiplicationResult);

    cout << "\nTranspose of Matrix 1:\n";
    Matrix transposeResult = transposeMatrix(matrix1);
    displayMatrix(transposeResult);

    return 0;
}
