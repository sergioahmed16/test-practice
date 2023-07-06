#include <iostream>
#include <vector>

void Intercambiar(std::vector<int>& arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Pivote(std::vector<int>& arr, int i, int j)
{
    int p = arr[i]; // Elige el primer elemento como pivote
    int k = i;
    int l = j + 1;

    do
    {
        do
        {
            k++;
        } while (k <= j && arr[k] <= p);

        do
        {
            l--;
        } while (arr[l] > p);

        if (k < l)
        {
            Intercambiar(arr, k, l);
        }
    } while (k < l);

    Intercambiar(arr, i, l);
    return l;
}

void Quicksort(std::vector<int>& arr, int i, int j)
{
    if (i < j)
    {
        int l = Pivote(arr, i, j);
        Quicksort(arr, i, l - 1);
        Quicksort(arr, l + 1, j);
    }
}

int main()
{
    std::vector<int> arr = {9, 3, 7, 1, 5, 6, 4, 8, 2, 10};  // Vector de 10 elementos

    std::cout << "Arreglo original: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    Quicksort(arr, 0, arr.size() - 1);

    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
