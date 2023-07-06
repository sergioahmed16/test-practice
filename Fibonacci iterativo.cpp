#include <iostream>

unsigned long fibonacci(unsigned n)
{
    if (n <= 1)
        return n;

    unsigned long prev1 = 0;
    unsigned long prev2 = 1;
    unsigned long current;

    for (unsigned i = 2; i <= n; ++i)
    {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }

    return current;
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