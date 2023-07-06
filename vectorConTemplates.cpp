#include <iostream>

template <typename Tipo>
class CVector
{
private:
    Tipo* m_pVect;  // Puntero al búfer
    int m_nCount,   // Controla cuántos elementos se están utilizando realmente
        m_nMax,     // Controla el número de elementos asignados
        m_nDelta;   // Para controlar el crecimiento

    void Inicializar(int delta);   // Inicializa las variables privadas, etc.
    void Redimensionar();          // Redimensiona el vector cuando ocurre un desbordamiento

public:
    CVector(int delta = 10);    // Constructor
    void Insertar(const Tipo& elem);     // Inserta un nuevo elemento
    int ObtenerTamanio() const;  // Obtiene el tamaño actual del vector
    Tipo& operator[](int indice); // Obtiene o establece el elemento en el índice especificado
};

// Implementación de la clase CVector
template <typename Tipo>
CVector<Tipo>::CVector(int delta)
{
    Inicializar(delta);
}

template <typename Tipo>
void CVector<Tipo>::Insertar(const Tipo& elem)
{
    if (m_nCount == m_nMax)   // Verificar el desbordamiento
        Redimensionar();            // Redimensionar el vector antes de insertar elem
    m_pVect[m_nCount++] = elem;  // Insertar el elemento al final
}

template <typename Tipo>
void CVector<Tipo>::Inicializar(int delta)
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = new Tipo[m_nMax];
}

template <typename Tipo>
void CVector<Tipo>::Redimensionar()
{
    m_nMax += m_nDelta;
    Tipo* temp = new Tipo[m_nMax];
    for (int i = 0; i < m_nCount; i++)
        temp[i] = m_pVect[i];
    delete[] m_pVect;
    m_pVect = temp;
}

template <typename Tipo>
int CVector<Tipo>::ObtenerTamanio() const
{
    return m_nCount;
}

template <typename Tipo>
Tipo& CVector<Tipo>::operator[](int indice)
{
    return m_pVect[indice];
}

int main()
{
    // Crear una instancia de CVector con tipo int
    CVector<int> miVector;

    // Insertar elementos en el vector
    miVector.Insertar(5);
    miVector.Insertar(10);
    miVector.Insertar(15);

    // Imprimir los elementos del vector
    for (int i = 0; i < miVector.ObtenerTamanio(); i++)
    {
        std::cout << miVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
