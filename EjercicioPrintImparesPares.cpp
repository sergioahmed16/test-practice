#include <iostream>

int main()
{
    int N;
    std::cout << "Ingrese el valor de N: ";
    std::cin >> N;

    int contadorLinea1 = 0;
    int contadorLinea2 = 0;
    int contadorLinea3 = 0;
    int contadorLinea4 = 0;
    int contadorLinea5 = 0;
    int contadorLinea6 = 0;

    for (int i = 0; i <= N; i++)
    {
        contadorLinea1++;  // Incrementa el contador de la línea 1

        if (i % 2 == 0)
        {
            contadorLinea2++;  // Incrementa el contador de la línea 2

            std::cout << i << std::endl;

            contadorLinea3++;  // Incrementa el contador de la línea 3
        }
                else{
        contadorLinea2++;  // Incrementa el contador de la línea 5
        }

    }        
    contadorLinea1++;  // Incrementa el contador de la línea 1


    for (int i = 0; i <= N; i++)
    {
        contadorLinea4++;  // Incrementa el contador de la línea 4

        if (i % 2 != 0)
        {
            contadorLinea5++;  // Incrementa el contador de la línea 5

            std::cout << i << std::endl;
             contadorLinea6++; 
        }
        else{
        contadorLinea5++;  // Incrementa el contador de la línea 5
        }
    }
    contadorLinea4++;  // Incrementa el contador de la línea 4


    // Muestra los contadores de cada línea
    std::cout << "Contador línea 1: " << contadorLinea1 << std::endl;
    std::cout << "Contador línea 2: " << contadorLinea2 << std::endl;
    std::cout << "Contador línea 3: " << contadorLinea3 << std::endl;
    std::cout << "Contador línea 4: " << contadorLinea4 << std::endl;
    std::cout << "Contador línea 5: " << contadorLinea5 << std::endl;
    std::cout << "Contador línea 6: " << contadorLinea6 << std::endl;

    return 0;
}
