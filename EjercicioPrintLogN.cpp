#include <iostream>
//i=1
//while(i<N):
//print i
//i=i*2
int main()
{
    int N;
    std::cout << "Ingrese el valor de N: ";
    std::cin >> N;

    int contadorLinea1 = 0;
    int contadorLinea2 = 0;
    int contadorLinea3 = 0;

    int i = 1;
    while (i < N)
    {
        contadorLinea1++;  // Incrementa el contador de la línea 1

        std::cout << i << std::endl;

        contadorLinea2++;  // Incrementa el contador de la línea 2

        i = i * 2;

        contadorLinea3++;  // Incrementa el contador de la línea 3
    }
    contadorLinea1++;  // Incrementa el contador de la línea 1


    // Muestra los contadores de cada línea
    std::cout << "Contador línea 1: " << contadorLinea1 << std::endl;
    std::cout << "Contador línea 2: " << contadorLinea2 << std::endl;
    std::cout << "Contador línea 3: " << contadorLinea3 << std::endl;

    return 0;
}
