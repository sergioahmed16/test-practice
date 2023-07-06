#include <iostream>

float Addition(float a, float b)
{
    return a + b;
}

float Subtraction(float a, float b)
{
    return a - b;
}

float Multiplication(float a, float b)
{
    return a * b;
}

float Division(float a, float b)
{
    if (b != 0)
        return a / b;
    else
        return 0;  // Manejo del caso de división por cero
}

int main()
{
    float a, b, c;
    int opt;

    // Operación de suma
    std::cout << "Ingrese dos números para sumar: ";
    std::cin >> a >> b;
    opt = 0;
    c = Addition(a, b);
    std::cout << "Resultado de la suma: " << c << std::endl;

    // Operación de multiplicación
    std::cout << "Ingrese dos números para multiplicar: ";
    std::cin >> a >> b;
    opt = 2;
    c = Multiplication(a, b);
    std::cout << "Resultado de la multiplicación: " << c << std::endl;

    return 0;
}