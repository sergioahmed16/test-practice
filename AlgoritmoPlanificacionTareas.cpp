#include <iostream>
#include <vector>
#include <algorithm>

struct Tarea
{
    int beneficio;
    int plazo;
};

bool compararPorBeneficio(const Tarea& tarea1, const Tarea& tarea2)
{
    return tarea1.beneficio > tarea2.beneficio;
}

int PlanificacionVoraz(int n, const std::vector<int>& b, const std::vector<int>& d)
{
    std::vector<Tarea> tareas;

    for (int i = 0; i < n; i++)
    {
        Tarea tarea;
        tarea.beneficio = b[i];
        tarea.plazo = d[i];
        tareas.push_back(tarea);
    }

    std::sort(tareas.begin(), tareas.end(), compararPorBeneficio);

    std::vector<int> resultado(n, -1); // Inicializar el resultado con -1 (ninguna tarea asignada)

    int totalBeneficio = 0;
    int ultimoPlazoDisponible = n; // El último plazo disponible inicialmente es igual al número de tareas

    for (int i = 0; i < n; i++)
    {
        int plazo = tareas[i].plazo;
        while (plazo > 0 && resultado[plazo - 1] != -1)
        {
            plazo--; // Buscar el siguiente plazo disponible
        }

        if (plazo > 0)
        {
            resultado[plazo - 1] = i; // Asignar la tarea al plazo disponible
            totalBeneficio += tareas[i].beneficio;
        }
    }

    // Mostrar el resultado
    std::cout << "Planificación de tareas: ";
    for (int i = 0; i < n; i++)
    {
        if (resultado[i] != -1)
        {
            std::cout << resultado[i] << " ";
        }
    }
    std::cout << std::endl;

    return totalBeneficio;
}

int main()
{
    int n = 4;

    std::vector<int> b = {100, 10, 15, 27};
    std::vector<int> d = {2, 1, 2, 1};

    int beneficioTotal = PlanificacionVoraz(n, b, d);

    std::cout << "Beneficio total obtenido: " << beneficioTotal << std::endl;

    return 0;
}
