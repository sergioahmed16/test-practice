#include <iostream>

class CArithmetic
{
private:
    // Algunos atributos van aquí

public:
    static double Addition(double a, double b);
    static double Substraction(double a, double b);
    static double Multiplication(double a, double b);
    static double Division(double a, double b);
    // Más métodos van aquí
};

double CArithmetic::Addition(double a, double b)
{
    return a + b;
}

double CArithmetic::Substraction(double a, double b)
{
    return a - b;
}

double CArithmetic::Multiplication(double a, double b)
{
    return a * b;
}

double CArithmetic::Division(double a, double b)
{
    if (b != 0)
        return a / b;
    else
        return 0;  // Manejo del caso de división por cero
}

int main()
{
    double a, b, c;
    int opt;

    // Operación de suma
    std::cout << "Ingrese dos números para sumar: ";
    std::cin >> a >> b;
    opt = 0;
    c = CArithmetic::Addition(a, b);
    std::cout << "Resultado de la suma: " << c << std::endl;

    // Operación de multiplicación
    std::cout << "Ingrese dos números para multiplicar: ";
    std::cin >> a >> b;
    opt = 2;
    c = CArithmetic::Multiplication(a, b);
    std::cout << "Resultado de la multiplicación: " << c << std::endl;

    return 0;
}