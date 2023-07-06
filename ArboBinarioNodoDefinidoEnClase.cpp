#include <iostream>

template <typename T>
class CBinaryTree
{
private:
    struct NODE
    {
        T m_data;
        NODE* m_pLeft;
        NODE* m_pRight;

        NODE(const T& data)
            : m_data(data), m_pLeft(nullptr), m_pRight(nullptr) {}
    };

    NODE* m_pRoot;

public:
    CBinaryTree()
        : m_pRoot(nullptr) {}

    ~CBinaryTree()
    {
        Clear();
    }

    void Add(const T& data)
    {
        NODE* newNode = new NODE(data);
        if (m_pRoot == nullptr)
        {
            m_pRoot = newNode;
        }
        else
        {
            AddNode(m_pRoot, newNode);
        }
    }

    void Display()
    {
        DisplayInOrder(m_pRoot);
        std::cout << std::endl;
    }

    void Clear()
    {
        ClearTree(m_pRoot);
        m_pRoot = nullptr;
    }

private:
    void AddNode(NODE* currentNode, NODE* newNode)
    {
        if (newNode->m_data < currentNode->m_data)
        {
            if (currentNode->m_pLeft == nullptr)
            {
                currentNode->m_pLeft = newNode;
            }
            else
            {
                AddNode(currentNode->m_pLeft, newNode);
            }
        }
        else
        {
            if (currentNode->m_pRight == nullptr)
            {
                currentNode->m_pRight = newNode;
            }
            else
            {
                AddNode(currentNode->m_pRight, newNode);
            }
        }
    }

    void DisplayInOrder(NODE* currentNode)
    {
        if (currentNode != nullptr)
        {
            DisplayInOrder(currentNode->m_pLeft);
            std::cout << currentNode->m_data << " ";
            DisplayInOrder(currentNode->m_pRight);
        }
    }

    void ClearTree(NODE* currentNode)
    {
        if (currentNode != nullptr)
        {
            ClearTree(currentNode->m_pLeft);
            ClearTree(currentNode->m_pRight);
            delete currentNode;
        }
    }
};

int main()
{
    CBinaryTree<int> myTree;

    myTree.Add(50);
    myTree.Add(30);
    myTree.Add(70);
    myTree.Add(20);
    myTree.Add(40);
    myTree.Add(60);
    myTree.Add(80);

    std::cout << "Elementos: ";
    myTree.Display();

    myTree.Clear();

    return 0;
}
