#include <iostream>
#include <vector>
#include <algorithm>
int BinarySearch(const std::vector<int>& arr, int key, int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Si el elemento no se encuentra en el arreglo
}

int main()
{
    std::vector<int> arr = {5, 2, 7, 9, 3, 2, 1, 6};
    int key = 7;

    // Ordenar el arreglo 
    std::sort(arr.begin(), arr.end());

    int index = BinarySearch(arr, key, 0, arr.size() - 1);

    if (index != -1)
        std::cout << "El número " << key << " se encuentra en la posición " << index << std::endl;
    else
        std::cout << "El número " << key << " no se encuentra en el arreglo." << std::endl;

    return 0;
}
