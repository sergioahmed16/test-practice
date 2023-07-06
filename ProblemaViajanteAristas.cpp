#include <iostream>
#include <vector>
#include <algorithm>

struct Arista
{
    int ciudad1;
    int ciudad2;
    double distancia;
};

bool compararDistancias(const Arista& arista1, const Arista& arista2)
{
    return arista1.distancia < arista2.distancia;
}

int encontrarGrupo(std::vector<int>& grupos, int ciudad)
{
    if (grupos[ciudad] == ciudad)
        return ciudad;
    return encontrarGrupo(grupos, grupos[ciudad]);
}

void unirGrupos(std::vector<int>& grupos, int ciudad1, int ciudad2)
{
    int grupo1 = encontrarGrupo(grupos, ciudad1);
    int grupo2 = encontrarGrupo(grupos, ciudad2);
    grupos[grupo2] = grupo1;
}

std::vector<int> resolverViajante(const std::vector<std::vector<double>>& distancias)
{
    int numCiudades = distancias.size();
    std::vector<Arista> aristas;

    // Construir lista de aristas
    for (int i = 0; i < numCiudades; i++)
    {
        for (int j = i + 1; j < numCiudades; j++)
        {
            aristas.push_back({i, j, distancias[i][j]});
        }
    }

    // Ordenar aristas por distancia creciente
    std::sort(aristas.begin(), aristas.end(), compararDistancias);

    std::vector<int> grupos(numCiudades);
    for (int i = 0; i < numCiudades; i++)
    {
        grupos[i] = i;
    }

    std::vector<int> ruta;
    for (const Arista& arista : aristas)
    {
        int ciudad1 = arista.ciudad1;
        int ciudad2 = arista.ciudad2;

        if (encontrarGrupo(grupos, ciudad1) != encontrarGrupo(grupos, ciudad2))
        {
            ruta.push_back(ciudad1);
            unirGrupos(grupos, ciudad1, ciudad2);
        }
    }

    // Agregar última ciudad y volver al punto de partida
    ruta.push_back(aristas.back().ciudad2);
    ruta.push_back(aristas.back().ciudad1);

    return ruta;
}

int main()
{
    std::vector<std::vector<double>> distancias = {
        {0.0, 2.0, 4.0, 3.0, 1.0},
        {2.0, 0.0, 5.0, 2.0, 1.5},
        {4.0, 5.0, 0.0, 1.0, 3.0},
        {3.0, 2.0, 1.0, 0.0, 2.5},
        {1.0, 1.5, 3.0, 2.5, 0.0}
    };

    std::vector<int> ruta = resolverViajante(distancias);

    std::cout << "Ruta óptima: ";
    for (int ciudad : ruta)
    {
        std::cout << ciudad << " ";
    }
    std::cout << std::endl;

    return 0;
}
