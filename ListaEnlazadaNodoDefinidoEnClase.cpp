#include <vector>
#include <list>
#include <iostream>

template <typename T>
class CLinkedList
{
private:
    struct NODE
    {
        T m_data;           // Los datos se almacenan aquí
        NODE* m_pNext;      // Puntero al siguiente nodo

        NODE(const T& data) // Constructor del nodo
            : m_data(data), m_pNext(nullptr) {}
    };

    NODE* m_pRoot;          // Puntero al inicio de la lista

public:
    CLinkedList()           // Constructor de la lista enlazada
        : m_pRoot(nullptr) {}

    ~CLinkedList()          // Destructor de la lista enlazada
    {
        Clear();
    }

    void Add(const T& data) // Método para agregar un nuevo elemento al principio de la lista
    {
        NODE* newNode = new NODE(data);
        newNode->m_pNext = m_pRoot;
        m_pRoot = newNode;
    }

    void Display()          // Método para mostrar los elementos en la lista
    {
        NODE* current = m_pRoot;
        while (current != nullptr)
        {
            std::cout << current->m_data << " ";
            current = current->m_pNext;
        }
        std::cout << std::endl;
    }

    void Clear()            // Método para limpiar la lista y liberar memoria
    {
        NODE* current = m_pRoot;
        while (current != nullptr)
        {
            NODE* nextNode = current->m_pNext;
            delete current;
            current = nextNode;
        }
        m_pRoot = nullptr;
    }
};

int main()
{
    CLinkedList<int> myList;

    myList.Add(4);
    myList.Add(5);
    myList.Add(6);

    myList.Display();   

    myList.Clear();

    return 0;
}
