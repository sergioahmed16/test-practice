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
        throw 0;  // Lanzar una excepción de tipo int cuando se produce una división por cero
}

int main()
{
    double x, y, z;

    // Ingresar los valores para x y y
    std::cout << "Ingrese el valor de x: ";
    std::cin >> x;
    std::cout << "Ingrese el valor de y: ";
    std::cin >> y;

    try
    {
        // Nuestra sección crítica con posibles excepciones comienza aquí
        z = CArithmetic::Division(x, y);
        std::cout << "Resultado de la división: " << z << std::endl;
    }
    catch (int errorcode)
    {
        // Captura la excepción y muestra un mensaje adecuado
        std::cout << "Error: División por cero." << std::endl;
    }

    return 0;
}
