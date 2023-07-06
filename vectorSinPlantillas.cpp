#include <iostream>
#include <cstring>
class CVector
{
private:
    void** m_pVect;                          // Puntero al buffer
    int m_nCount;                             // Controla cuántos elementos se están utilizando
    int m_nMax;                               // Controla la cantidad de elementos asignados
    int m_nDelta;                             // Para controlar el crecimiento (el vector crece m_nDelta unidades cada vez que sea necesario)
    int m_nTamElem;                           // Tamaño de cada elemento
    int (*m_lpfnComparar)(void*, void*);       // Puntero a la función de comparación

public:
    CVector(int (*lpfnComparar)(void*, void*), int tamElem, int delta = 10)
        : m_pVect(nullptr), m_nCount(0), m_nMax(0), m_nDelta(delta), m_nTamElem(tamElem), m_lpfnComparar(lpfnComparar)
    {
        Inicializar(delta);
    }

    ~CVector()
    {
        Limpiar();
    }

    void Insertar(void* elem)
    {
        if (m_nCount == m_nMax)                 // Verificar el desbordamiento
            Redimensionar();                    // Redimensionar el vector antes de insertar el elemento
        m_pVect[m_nCount++] = DuplicarBloque(elem);  // Insertar el elemento al final
    }

    void Imprimir() const
    {
        for (int i = 0; i < m_nCount; i++)
        {
            void* elemento = m_pVect[i];
            std::cout << *static_cast<int*>(elemento) << " ";  // Suponiendo que los elementos son enteros
        }
        std::cout << std::endl;
    }

private:
    void Inicializar(int delta)
    {
        m_nCount = 0;
        m_nMax = delta;
        m_pVect = new void*[m_nMax];
    }

    void Redimensionar()
    {
        m_nMax += m_nDelta;
        void** temp = new void*[m_nMax];
        for (int i = 0; i < m_nCount; i++)
            temp[i] = m_pVect[i];
        delete[] m_pVect;
        m_pVect = temp;
    }

    void Limpiar()
    {
        delete[] m_pVect;
        m_pVect = nullptr;
        m_nCount = 0;
        m_nMax = 0;
    }

    void* DuplicarBloque(void* pElem)
    {
        void* p = new char[m_nTamElem];
        return memcpy(p, pElem, m_nTamElem);
    }
};

// Función de comparación para enteros
int CompararEnteros(void* a, void* b)
{
    int* ptrA = static_cast<int*>(a);
    int* ptrB = static_cast<int*>(b);
    return (*ptrA - *ptrB);
}

int main()
{
    CVector miVector(CompararEnteros, sizeof(int));

    int a = 1;
    int b = 2;
    int c = 3;

    miVector.Insertar(&a);
    miVector.Insertar(&b);
    miVector.Insertar(&c);
// Salida: 1,2,3
    miVector.Imprimir();   

    return 0;
}
