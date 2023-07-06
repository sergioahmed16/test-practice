#include <iostream>
#include <vector>

using namespace std;

// sumar dos matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }

    return resultado;
}

// restar dos matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }

    return resultado;
}

//  multiplicar dos matrices usando el algoritmo de Strassen
vector<vector<int>> multiplicarStrassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int mitad = n / 2;

    // Dividir las matrices en submatrices (DIVIDE Y VENCERAS)
    vector<vector<int>> A11(mitad, vector<int>(mitad));
    vector<vector<int>> A12(mitad, vector<int>(mitad));
    vector<vector<int>> A21(mitad, vector<int>(mitad));
    vector<vector<int>> A22(mitad, vector<int>(mitad));

    vector<vector<int>> B11(mitad, vector<int>(mitad));
    vector<vector<int>> B12(mitad, vector<int>(mitad));
    vector<vector<int>> B21(mitad, vector<int>(mitad));
    vector<vector<int>> B22(mitad, vector<int>(mitad));

    for (int i = 0; i < mitad; ++i) {
        for (int j = 0; j < mitad; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mitad];
            A21[i][j] = A[i + mitad][j];
            A22[i][j] = A[i + mitad][j + mitad];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mitad];
            B21[i][j] = B[i + mitad][j];
            B22[i][j] = B[i + mitad][j + mitad];
        }
    }

    // Calcula las siete multiplicaciones de Strassen recursivamente
    vector<vector<int>> P1 = multiplicarStrassen(A11, restarMatrices(B12, B22));
    vector<vector<int>> P2 = multiplicarStrassen(sumarMatrices(A11, A12), B22);
    vector<vector<int>> P3 = multiplicarStrassen(sumarMatrices(A21, A22),B11);
    vector<vector<int>> P4 = multiplicarStrassen(A22, restarMatrices(B21, B11));
    vector<vector<int>> P5 = multiplicarStrassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
    vector<vector<int>> P6 = multiplicarStrassen(restarMatrices(A12, A22), sumarMatrices(B21, B22));
    vector<vector<int>> P7 = multiplicarStrassen(restarMatrices(A11, A21), sumarMatrices(B11, B12));

    // Calcular las submatrices del resultado
    vector<vector<int>> C11 = sumarMatrices(restarMatrices(sumarMatrices(P5, P4), P2), P6);
    vector<vector<int>> C12 = sumarMatrices(P1, P2);
    vector<vector<int>> C21 = sumarMatrices(P3, P4);
    vector<vector<int>> C22 = restarMatrices(restarMatrices(sumarMatrices(P5, P1), P3), P7);

    // Combinar las submatrices en la matriz resultado
    vector<vector<int>> resultado(n, vector<int>(n));

    for (int i = 0; i < mitad; ++i) {
        for (int j = 0; j < mitad; ++j) {
            resultado[i][j] = C11[i][j];
            resultado[i][j + mitad] = C12[i][j];
            resultado[i + mitad][j] = C21[i][j];
            resultado[i + mitad][j + mitad] = C22[i][j];
        }
    }

    return resultado;
}

// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> B = {
        {7, 8, 9, 10},
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 3, 1, 2}
    };

    vector<vector<int>> resultado = multiplicarStrassen(A, B);

    cout << "Matriz 1:" << endl;
    imprimirMatriz(A);

    cout << endl;

    cout << "Matriz 2:" << endl;
    imprimirMatriz(B);

    cout << endl;

    cout << "Resultado:" << endl;
    imprimirMatriz(resultado);

    return 0;
}
