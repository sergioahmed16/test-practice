#include <iostream>
#include <vector>
#include <map>

std::map<int, std::string> valorMonedas = {
    {200, "2 euros"},
    {100, "1 euro"},
    {50, "50 céntimos"},
    {20, "20 céntimos"},
    {10, "10 céntimos"},
    {5, "5 céntimos"},
    {2, "2 céntimos"},
    {1, "1 céntimo"}
};

std::map<int, int> DevolverMonedas(float cantidad)
{
    std::map<int, int> monedasUtilizadas;

    int cantidadEnCentimos = cantidad * 100;

    for (auto it = valorMonedas.rbegin(); it != valorMonedas.rend(); ++it)
    {
        int valorMoneda = it->first;
        int cantidadMonedas = cantidadEnCentimos / valorMoneda;

        monedasUtilizadas[valorMoneda] = cantidadMonedas;
        cantidadEnCentimos %= valorMoneda;
    }

    return monedasUtilizadas;
}

int main()
{
    float cantidad = 3.89;

    std::map<int, int> monedasUtilizadas = DevolverMonedas(cantidad);

    std::cout << "Monedas utilizadas para devolver " << cantidad << " euros:" << std::endl;
    for (auto it = monedasUtilizadas.begin(); it != monedasUtilizadas.end(); ++it)
    {
        int valorMoneda = it->first;
        int cantidadMonedas = it->second;

        std::cout << cantidadMonedas << " " << valorMonedas[valorMoneda] << std::endl;
    }

    return 0;
}
