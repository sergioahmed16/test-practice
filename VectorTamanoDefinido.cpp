#include <iostream>
#include <vector>

const int MAX_SIZE = 1000; 

class FixedSizeVector {
private:
    int gVect[MAX_SIZE]; // Vector de tamaño fijo
    int gnCount; // Contador de elementos en el vector

public:
    FixedSizeVector() : gnCount(0) {} // Constructor

    void Insert(int elem) {
        if (gnCount < MAX_SIZE) {
            gVect[gnCount++] = elem; // Insertar el elemento al final
        }
    }

    void PrintVector() {
        for (int i = 0; i < gnCount; i++) {
            std::cout << gVect[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    FixedSizeVector vector;

    vector.Insert(1);
    vector.Insert(2);
    vector.Insert(3);
    vector.Insert(5);

    vector.PrintVector();

    return 0;
}
