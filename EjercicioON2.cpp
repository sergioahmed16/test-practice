#include <iostream>
//for I=0 to N:
    //for j=i to N:
      //  print i +","+j
int main()
{
    int N;
    std::cout << "Ingrese el valor de N: ";
    std::cin >> N;

    int contador1 = 0;
    int contador2 = 0;
    int contador3 = 0;

    for (int i = 0; i <= N; i++)
    {
        contador1++;  // Incrementa el contador de la línea 1

        for (int j = i; j <= N; j++)
        {
            
            contador2++;  // Incrementa el contador de la línea 2

            std::cout << i << "," << j << std::endl;

            contador3++;  // Incrementa el contador de la línea 3
        }
        contador2++; 
    }
    contador1++;

    // Muestra los contadores de cada línea
    std::cout << "Contador  1: " << contador1 << std::endl;
    std::cout << "Contador  2: " << contador2 << std::endl;
    std::cout << "Contador  3: " << contador3 << std::endl;

    return 0;
}
