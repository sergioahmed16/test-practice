#include <vector>
#include <list>
#include <iostream>

template <typename T>
struct NODE
{
    T m_data;                // Los datos se almacenan aquí
    NODE<T>* m_pNext;        // Puntero al siguiente nodo
    static long id;          // Identificador del nodo

    NODE()                  // Constructor
        : m_data(0), m_pNext(nullptr) {}
};

template <typename T>
long NODE<T>::id = 0;       // Inicialización del identificador del nodo

template <typename T>
class CLinkedList
{
private:
    NODE<T>* m_pRoot;       // Puntero al inicio de la lista

public:
    CLinkedList()           // Constructor
        : m_pRoot(nullptr) {}

    // Método para agregar un nuevo elemento al principio de la lista
    void Agregar(const T& dato)
    {
        NODE<T>* nuevoNodo = new NODE<T>();
        nuevoNodo->m_data = dato;
        nuevoNodo->m_pNext = m_pRoot;
        m_pRoot = nuevoNodo;
    }

    // Método para mostrar los elementos en la lista
    void Mostrar()
    {
        NODE<T>* actual = m_pRoot;
        while (actual != nullptr)
        {
            std::cout << actual->m_data << " ";
            actual = actual->m_pNext;
        }
        std::cout << std::endl;
    }

    // Método para limpiar la lista y liberar memoria
    void Limpiar()
    {
        NODE<T>* actual = m_pRoot;
        while (actual != nullptr)
        {
            NODE<T>* siguienteNodo = actual->m_pNext;
            delete actual;
            actual = siguienteNodo;
        }
        m_pRoot = nullptr;
    }
};
int main()
{
    CLinkedList<int> miLista;

    miLista.Agregar(2);
    miLista.Agregar(6);
    miLista.Agregar(7);

    miLista.Mostrar();   

    miLista.Limpiar();

    return 0;
}