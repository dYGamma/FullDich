#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ������� ��� ������ ������� �� �����
void printMatrix(vector<vector<double>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// ������� ��� ���������� ������������ �������
// �������� ������������ ������� ����������, ������� ���������� �� ������ ������.
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

// ������� ��� ���������� �������� �������
// ��������� �������� ������� ������� ������������ ��������������. ��� ����� ��� ��������� ������������ ������� � ���������, 
// ��� �� �� ����� ���� (��� ��� �������� ������� ����� ��������� ������ ��� ������������� ������). 
// ����� ��� ��������� ������ ������� �������� ������� ��� ��������������� �����, �������� �� ������������ �������.
vector<vector<double>> inverseMatrix(vector<vector<double>> matrix) {
    int n = matrix.size();
    vector<vector<double>> inverse(n, vector<double>(n));
    double det = determinant(matrix);
    if (det == 0) {
        cout << "������: ������������ ������� ����� ����." << endl;
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
    // ���� ����������� ������� � ��������� ������ A � B
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "������� ����������� ������� A: ";
    cin >> n;
    vector<vector<double>> A(n, vector<double>(n));
    cout << "������� �������� ������� A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    vector<double> B(n);
    cout << "������� �������� ������� B:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // ������� ����
    vector<vector<double>> A_inverse = inverseMatrix(A);
    vector<double> X(n);
    for (int i = 0; i < n; i++) {
        X[i] = 0;
        for (int j = 0; j < n; j++) {
            X[i] += A_inverse[i][j] * B[j];
        }
    }

    // ����� ������� �� �����
    cout << "������� ���� AX = B:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "X" << i + 1 << " = " << X[i] << endl;
    }

    return 0;
}
