#include <iostream>
#include <vector>
//for i=0 to length(A):
//    for j=0 to length(B):
  //      print A[i] +","+B[j]
int main()
{
    std::vector<int> A = {23, 22, 13};  
    std::vector<int> B = {42, 51, 64};  

    int contadorLinea1 = 0;
    int contadorLinea2 = 0;
    int contadorLinea3 = 0;

    for (int i = 0; i < A.size(); i++)
    {
        contadorLinea1++;  // Incrementa el contador de la línea 1

        for (int j = 0; j < B.size(); j++)
        {
            contadorLinea2++;  // Incrementa el contador de la línea 2

            std::cout << A[i] << "," << B[j] << std::endl;

            contadorLinea3++;  // Incrementa el contador de la línea 3
        }
        contadorLinea2++;  // Incrementa el contador de la línea 2
    }
contadorLinea1++;  // Incrementa el contador de la línea 1
    // Muestra los contadores de cada línea
    std::cout << "Contador  1: " << contadorLinea1 << std::endl;
    std::cout << "Contador  2: " << contadorLinea2 << std::endl;
    std::cout << "Contador  3: " << contadorLinea3 << std::endl;

    return 0;
}
