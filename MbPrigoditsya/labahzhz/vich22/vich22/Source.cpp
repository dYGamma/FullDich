#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для вывода матрицы на экран
void printMatrix(vector<vector<double>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функция для вычисления определителя матрицы
// Вычислим определитель матрицы рекурсивно, методом разложения по первой строке.
double determinant(vector<vector<double>> matrix) {
    int n = matrix.size();
    double det = 0;
    if (n == 1) {
        det = matrix[0][0];
    }
    else {
        for (int k = 0; k < n; k++) {
            vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
            for (int i = 1; i < n; i++) {
                int j = 0;
                for (int l = 0; l < n; l++) {
                    if (l != k) {
                        submatrix[i - 1][j] = matrix[i][l];
                        j++;
                    }
                }
            }
            det += pow(-1, k) * matrix[0][k] * determinant(submatrix);
        }
    }
    return det;
}

// Функция для вычисления обратной матрицы
// вычисляет обратную матрицу методом элементарных преобразований. Для этого она вычисляет определитель матрицы и проверяет, 
// что он не равен нулю (так как обратную матрицу можно вычислить только для невырожденных матриц). 
// затем она вычисляет каждый элемент обратной матрицы как соответствующий минор, деленный на определитель матрицы.
vector<vector<double>> inverseMatrix(vector<vector<double>> matrix) {
    int n = matrix.size();
    vector<vector<double>> inverse(n, vector<double>(n));
    double det = determinant(matrix);
    if (det == 0) {
        cout << "Ошибка: определитель матрицы равен нулю." << endl;
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
            int p = 0;
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    int q = 0;
                    for (int l = 0; l < n; l++) {
                        if (l != j) {
                            submatrix[p][q] = matrix[k][l];
                            q++;
                        }
                    }
                    p++;
                }
            }
            double subdet = determinant(submatrix);
            inverse[j][i] = pow(-1, i + j) * subdet / det;
        }
    }
    return inverse;
}

int main() {
    // Ввод размерности матрицы и элементов матриц A и B
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размерность матрицы A: ";
    cin >> n;
    vector<vector<double>> A(n, vector<double>(n));
    cout << "Введите элементы матрицы A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    vector<double> B(n);
    cout << "Введите элементы вектора B:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // Решение СЛАУ
    vector<vector<double>> A_inverse = inverseMatrix(A);
    vector<double> X(n);
    for (int i = 0; i < n; i++) {
        X[i] = 0;
        for (int j = 0; j < n; j++) {
            X[i] += A_inverse[i][j] * B[j];
        }
    }

    // Вывод решения на экран
    cout << "Решение СЛАУ AX = B:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "X" << i + 1 << " = " << X[i] << endl;
    }

    return 0;
}
