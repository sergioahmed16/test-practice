#include <iostream>

unsigned long fibonacci(unsigned n)
{
    if (n <= 1)
        return n;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    unsigned int n;
    std::cout << "Ingrese el número de términos de la serie de Fibonacci: ";
    std::cin >> n;

    std::cout << "Serie de Fibonacci:" << std::endl;
    for (unsigned int i = 0; i < n; ++i)
    {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
