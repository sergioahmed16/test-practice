#include <iostream>

double Potencia(double base, int exponente)
{
    if (exponente == 0)
    {
        // Cualquier número elevado a 0 es 1
        return 1;
    }
    else if (exponente % 2 == 0)
    {
        // Si el exponente es par, dividimos y conquistamos
        double mitad = Potencia(base, exponente / 2);
        return mitad * mitad;
    }
    else
    {
        // Si el exponente es impar, dividimos y conquistamos y multiplicamos por la base
        double mitad = Potencia(base, exponente / 2);
        return mitad * mitad * base;
    }
}

int main()
{
    double base;
    int exponente;

    std::cout << "Ingrese la base: ";
    std::cin >> base;

    std::cout << "Ingrese el exponente: ";
    std::cin >> exponente;

    double resultado = Potencia(base, exponente);

    std::cout << "El resultado de " << base << " elevado a la " << exponente << " es: " << resultado << std::endl;

    return 0;
}
