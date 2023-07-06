#include <iostream>
#include <cstring>

class CVector
{
private:
    void** m_pVect;                          // Puntero al búfer
    int m_nCount;                             // Controla cuántos elementos se están utilizando
    int m_nMax;                               // Controla la cantidad de elementos asignados
    int m_nDelta;                             // Para controlar el crecimiento
    int m_nElemSize;                          // Tamaño de cada elemento
    int (*m_lpfnCompare)(void*, void*);       // Puntero a la función de comparación

public:
    CVector(int (*lpfnCompare)(void*, void*), int nElemSize, int delta = 10)
        : m_pVect(nullptr), m_nCount(0), m_nMax(0), m_nDelta(delta), m_nElemSize(nElemSize), m_lpfnCompare(lpfnCompare)
    {
        Init(delta);
    }

    ~CVector()
    {
        Clear();
    }

    void Insert(void* pElem)
    {
        if (m_nCount == m_nMax)                  // Verificar el desbordamiento
            Resize();                           // Redimensionar el vector antes de insertar el elemento
        m_pVect[m_nCount++] = DupBlock(pElem);  // Insertar el elemento al final
    }

    void Display() const
    {
        for (int i = 0; i < m_nCount; i++)
            std::cout << *static_cast<int*>(m_pVect[i]) << " ";
        std::cout << std::endl;
    }

private:
    void Init(int delta)
    {
        m_nCount = 0;
        m_nMax = delta;
        m_pVect = new void*[m_nMax];
    }

    void Resize()
    {
        m_nMax += m_nDelta;
        void** temp = new void*[m_nMax];
        for (int i = 0; i < m_nCount; i++)
            temp[i] = m_pVect[i];
        delete[] m_pVect;
        m_pVect = temp;
    }

    void Clear()
    {
        delete[] m_pVect;
        m_pVect = nullptr;
        m_nCount = 0;
        m_nMax = 0;
    }

    void* DupBlock(void* pElem)
    {
        void* p = new char[m_nElemSize];
        return memcpy(p, pElem, m_nElemSize);
    }
};

// Función de comparación para enteros
int fnIntCompare(void* pVar1, void* pVar2)
{
    return *(int*)pVar1 - *(int*)pVar2;
}

int main()
{
    CVector myVector(fnIntCompare, sizeof(int));

    int a = 5;
    int b = 7;
    int c = 2;

    myVector.Insert(&a);
    myVector.Insert(&b);
    myVector.Insert(&c);

    myVector.Display();   

    return 0;
}
