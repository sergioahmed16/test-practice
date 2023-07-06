#include <iostream>

int main()
{
    int N;
    std::cout << "Ingrese el valor de N: ";
    std::cin >> N;

    int contadorLinea1 = 0;
    int contadorLinea2 = 0;
    int contadorLinea3 = 0;

    for (int i = 0; i <= N; i++)
    {
        contadorLinea1++;  // Incrementa el contador de la línea 1

        if (i % 2 == 0)
        {
            contadorLinea2++;  // Incrementa el contador de la línea 2

            std::cout << i << std::endl;

            contadorLinea3++;  // Incrementa el contador de la línea 3
        }
        else
        {contadorLinea2++; 
            }
    }
    contadorLinea1++; 
    // Muestra los contadores de cada línea
    std::cout << "Contador línea 1: " << contadorLinea1 << std::endl;
    std::cout << "Contador línea 2: " << contadorLinea2 << std::endl;
    std::cout << "Contador línea 3: " << contadorLinea3 << std::endl;

    return 0;
}
