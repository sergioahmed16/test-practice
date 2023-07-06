#include <iostream>
//1. for i=0 to N:
 //2.    j=1
 //3.   while j<N:
   // 4.       print j
    //5.    j=j*2
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

    for (int i = 0; i <= N; i++)
    {
        contadorLinea1++;  // Incrementa el contador de la línea 1

        int j = 1;
        contadorLinea2++;  // Incrementa el contador de la línea 2

        while (j < N)
        {
            contadorLinea3++;  // Incrementa el contador de la línea 3

            std::cout << j << std::endl;
            contadorLinea4++;  // Incrementa el contador de la línea 4

            j = j * 2;
            contadorLinea5++;  // Incrementa el contador de la línea 5
        }
        contadorLinea3++;  // Incrementa el contador de la línea 3

    }
        contadorLinea1++;  // Incrementa el contador de la línea 1

    // Muestra los contadores de cada línea
    std::cout << "Contador línea 1: " << contadorLinea1 << std::endl;
    std::cout << "Contador línea 2: " << contadorLinea2 << std::endl;
    std::cout << "Contador línea 3: " << contadorLinea3 << std::endl;
    std::cout << "Contador línea 4: " << contadorLinea4 << std::endl;
    std::cout << "Contador línea 5: " << contadorLinea5 << std::endl;

    return 0;
}
