#include <iostream>
#include <vector>
#include <algorithm>

struct Objeto
{
    int peso;
    int beneficio;
};

bool compararPorRatio(const Objeto& obj1, const Objeto& obj2)
{
    double ratio1 = (double)obj1.beneficio / obj1.peso;
    double ratio2 = (double)obj2.beneficio / obj2.peso;
    return ratio1 > ratio2;
}

int MochilaVoraz(int n, int M, const std::vector<int>& p, const std::vector<int>& b)
{
    std::vector<Objeto> objetos;

    for (int i = 0; i < n; i++)
    {
        Objeto obj;
        obj.peso = p[i];
        obj.beneficio = b[i];
        objetos.push_back(obj);
    }

    std::sort(objetos.begin(), objetos.end(), compararPorRatio);

    int pesoTotal = 0;
    int beneficioTotal = 0;

    for (int i = 0; i < n; i++)
    {
        if (pesoTotal + objetos[i].peso <= M)
        {
            pesoTotal += objetos[i].peso;
            beneficioTotal += objetos[i].beneficio;
        }
        else
        {
            double fraccion = (double)(M - pesoTotal) / objetos[i].peso;
            beneficioTotal += fraccion * objetos[i].beneficio;
            break;
        }
    }

    return beneficioTotal;
}

int main()
{
    int n = 3;
    int M = 20;

    std::vector<int> p = {18, 15, 10};
    std::vector<int> b = {25, 24, 15};

    int beneficioMaximo = MochilaVoraz(n, M, p, b);

    std::cout << "El beneficio máximo obtenido es: " << beneficioMaximo << std::endl;

    return 0;
}
