#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
struct Ciudad
{
    int id;
    double x;
    double y;
};

double calcularDistancia(const Ciudad& ciudad1, const Ciudad& ciudad2)
{
    double dx = ciudad1.x - ciudad2.x;
    double dy = ciudad1.y - ciudad2.y;
    return std::sqrt(dx * dx + dy * dy);
}

int encontrarCiudadMasCercana(const std::vector<Ciudad>& ciudades, const std::vector<bool>& visitado, int ciudadActual)
{
    double distanciaMinima = std::numeric_limits<double>::max();
    int ciudadMasCercana = -1;

    for (size_t i = 0; i < ciudades.size(); i++)
    {
        if (i != ciudadActual && !visitado[i])
        {
            double distancia = calcularDistancia(ciudades[ciudadActual], ciudades[i]);
            if (distancia < distanciaMinima)
            {
                distanciaMinima = distancia;
                ciudadMasCercana = i;
            }
        }
    }

    return ciudadMasCercana;
}

std::vector<int> resolverViajante(const std::vector<Ciudad>& ciudades)
{
    int numCiudades = ciudades.size();
    std::vector<bool> visitado(numCiudades, false);
    std::vector<int> ruta;
    ruta.push_back(0); // Empezar desde la ciudad 0

    for (int i = 1; i < numCiudades; i++)
    {
        int ciudadActual = ruta.back();
        int ciudadMasCercana = encontrarCiudadMasCercana(ciudades, visitado, ciudadActual);
        ruta.push_back(ciudadMasCercana);
        visitado[ciudadMasCercana] = true;
    }

    return ruta;
}

int main()
{
    std::vector<Ciudad> ciudades = {
        {0, 0.0, 0.0},
        {1, 1.0, 3.0},
        {2, 2.0, 2.0},
        {3, 3.0, 3.0},
        {4, 4.0, 4.0}
    };

    std::vector<int> ruta = resolverViajante(ciudades);

    std::cout << "Ruta óptima: ";
    for (int ciudad : ruta)
    {
        std::cout << ciudad << " ";
    }
    std::cout << std::endl;

    return 0;
}
