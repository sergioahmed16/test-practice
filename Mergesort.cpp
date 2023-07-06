#include <iostream>
#include <vector>

void Combinar(std::vector<int>& arr, int inicio, int medio, int fin)
{
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    // Crear arreglos temporales para almacenar los elementos divididos
    std::vector<int> izquierda(n1);
    std::vector<int> derecha(n2);

    // Copiar elementos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        izquierda[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        derecha[j] = arr[medio + 1 + j];

    // Fusionar los arreglos temporales de manera ordenada
    int i = 0;
    int j = 0;
    int k = inicio; // Índice del arreglo original

    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            arr[k] = izquierda[i];
            i++;
        }
        else {
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de la sublista izquierda (si hay alguno)
    while (i < n1) {
        arr[k] = izquierda[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de la sublista derecha (si hay alguno)
    while (j < n2) {
        arr[k] = derecha[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<int>& arr, int inicio, int fin)
{
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;

        // Ordenar recursivamente la mitad izquierda y la mitad derecha
        MergeSort(arr, inicio, medio);
        MergeSort(arr, medio + 1, fin);

        // Combinar las dos mitades ordenadas
        Combinar(arr, inicio, medio, fin);
    }
}

int main()
{
    std::vector<int> numeros = {5, 2, 7, 9, 3, 2, 1, 6};
    int n = numeros.size();

    MergeSort(numeros, 0, n - 1);

    std::cout << "Numeros ordenados: ";
    for (int i = 0; i < n; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
