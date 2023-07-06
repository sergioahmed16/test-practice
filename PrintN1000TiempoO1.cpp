#include <iostream>

int main()
{
    int N = 1000;  // Valor de N

    int contadorLinea1 = 0;
    int contadorLinea2 = 0;
    int contadorLinea3 = 0;
    int contadorLinea4 = 0;
    int contadorLinea5 = 0;

    contadorLinea1++;  // Incrementa el contador de la línea 1

    if (N % 2 == 0)
    {
        contadorLinea2++;  // Incrementa el contador de la línea 2

        std::cout << "par" << std::endl;

        contadorLinea3++;  // Incrementa el contador de la línea 3
    }
    else
    {
        contadorLinea4++;  // Incrementa el contador de la línea 4

        std::cout << "impar" << std::endl;

        contadorLinea5++;  // Incrementa el contador de la línea 5
    }

    // Muestra los contadores de cada línea
    std::cout << "Contador línea 1: " << contadorLinea1 << std::endl;
    std::cout << "Contador línea 2: " << contadorLinea2 << std::endl;
    std::cout << "Contador línea 3: " << contadorLinea3 << std::endl;
    std::cout << "Contador línea 4: " << contadorLinea4 << std::endl;
    std::cout << "Contador línea 5: " << contadorLinea5 << std::endl;

    return 0;
}
