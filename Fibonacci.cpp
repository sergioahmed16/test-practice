#include <iostream>

unsigned long fibo(unsigned n)
{
    if (n < 2)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    unsigned int n;
    std::cout << "Ingrese el número de términos de la serie Fibonacci: ";
    std::cin >> n;

    std::cout << "Serie de Fibonacci:" << std::endl;
    for (unsigned int i = 0; i < n; ++i)
    {
        std::cout << fibo(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
