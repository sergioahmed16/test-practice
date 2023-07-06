#include <iostream>

class VectorDinamico {
private:
    int* gpVect;  // Puntero al vector
    int gnCount;  // Cantidad de elementos actualmente en el vector
    int gnMax;    // Capacidad máxima  del vector (se va modificando)

public:
    VectorDinamico(int max) {
        gpVect = new int[max];
        gnCount = 0;
        gnMax = max;
    }

    ~VectorDinamico() {
        delete[] gpVect;
    }

    void Insert(int elem) {
        if (gnCount == gnMax) {
            Resize();
        }
        gpVect[gnCount++] = elem;
    }

    void Resize() {
        int newMax = gnMax * 2;  // Duplicar la capacidad del vector
        int* newVect = new int[newMax];
        
        // Copiar los elementos existentes al nuevo vector
        for (int i = 0; i < gnCount; ++i) {
            newVect[i] = gpVect[i];
        }

        delete[] gpVect;  // Liberar la memoria del vector antiguo
        gpVect = newVect;
        gnMax = newMax;
    }

    void MostrarVector() {
        for (int i = 0; i < gnCount; ++i) {
            std::cout << gpVect[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    VectorDinamico vector(3);  // Crear un vector con capacidad inicial de 3 elementos

    vector.Insert(1);
    vector.Insert(22);
    vector.Insert(33);
    vector.Insert(44);
    vector.Insert(55);

    vector.MostrarVector();

    return 0;
}
