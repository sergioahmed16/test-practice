#include <iostream>

// Búsqueda binaria
int bsearch(double a[], double key, int l, int u)
{
    int m;

    // Caso base: no existencia del numero
    if (u < l)
        return -1;

    // Calcular el punto medio
    m = (l + u) / 2;

    // Si el elemento en el punto medio es == a la key, se ha encontrado el elemento buscado
    if (a[m] == key)
        return m;

    // Si el elemento en el punto medio es < que la key, buscar en la mitad derecha del arreglo
    if (a[m] < key)
        return bsearch(a, key, m + 1, u);
    // Si el elemento en el punto medio es > que la key, buscar en la mitad izquierda del arreglo
    else
        return bsearch(a, key, l, m - 1);
}

int main()
{
    double arr[] = {1, 3, 5, 7, 9};
    double key;

    std::cout << "Ingrese el elemento que desea buscar: ";
    std::cin >> key;

    int result = bsearch(arr, key, 0, sizeof(arr) / sizeof(arr[0]) - 1);

    if (result == -1)
        std::cout << "Elemento no encontrado." << std::endl;
    else
        std::cout << "Elemento encontrado en el índice: " << result << std::endl;

    return 0;
}
