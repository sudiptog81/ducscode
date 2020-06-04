#include <iostream>

using namespace std;

template <typename T>
class SinglyLinkedList
{
protected:
    struct Node<T> *head = NULL;
    struct Node<T> *tail = NULL;

public:
    ~SinglyLinkedList()
    {
        Node<T> *node = head;
        while (node != NULL)
        {
            Node<T> *nodeCurrent = node;
            node = node->next;
            delete nodeCurrent;
        }
    }

    bool empty()
    {
        return head == NULL || tail == NULL;
    }

    T getFront()
    {
        return head->key;
    }

    void pushFront(T key)
    {
        struct Node<T> *newNode = new Node<T>;
        newNode->key = key;
        newNode->next = head;
        head = newNode;
        if (empty())
            tail = head;
    }

    void popFront()
    {
        if (empty())
            throw;
        head = head->next;
        if (empty())
            tail = NULL;
    }

    T getBack()
    {
        return tail->key;
    }

    void pushBack(T key)
    {
        struct Node<T> *newNode = new Node<T>;
        newNode->key = key;
        newNode->next = NULL;
        if (empty())
            head = tail = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }

    void popBack()
    {
        if (empty())
            throw;
        if (head == tail)
            head = tail = NULL;
        else
        {
            struct Node<T> *node = head;
            while (node->next->next != NULL)
                node = node->next;
            node->next = NULL;
            tail = node;
        }
    }

    void insertAfter(struct Node<T> *node, T key)
    {
        struct Node<T> *newNode = new Node<T>;
        newNode->key = key;
        newNode->next = node->next;
        node->next = newNode;
        if (tail == node)
            tail = newNode;
    }

    void insertBefore(struct Node<T> *node, T key)
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            if (temp->next == node)
            {
                struct Node<T> *newNode = new Node<T>;
                newNode->key = key;
                newNode->next = node;
                temp->next = newNode;
                if (head == node)
                    head = newNode;
                return;
            }
            temp = temp->next;
        }
    }

    struct Node<T> *at(int index)
    {
        int indexCount = 0;
        Node<T> *node = head;
        while (node != NULL)
        {
            if (indexCount == index)
                return node;
            node = node->next;
            indexCount++;
        }
        throw;
    }

    int
    indexOf(T key)
    {
        int index = 0;
        Node<T> *node = head;
        while (node != NULL)
        {
            if (node->key == key)
                return index;
            node = node->next;
            index++;
        }
        return -1;
    }

    bool contains(T key)
    {
        Node<T> *node = head;
        while (node != NULL)
        {
            if (node->key == key)
                return true;
            node = node->next;
        }
        return false;
    }

    void display()
    {
        Node<T> *node = head;
        while (node->next != NULL)
        {
            cout << node->key << " -> ";
            node = node->next;
        }
        cout << node->key << endl;
        cout << "head: " << getFront() << endl;
        cout << "tail: " << getBack() << endl;
    }
};
