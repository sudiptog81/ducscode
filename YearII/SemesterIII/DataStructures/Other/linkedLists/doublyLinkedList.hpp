#include <iostream>

using namespace std;

template <typename T>
struct DLLNode
{
    T key;
    struct DLLNode *next;
    struct DLLNode *prev;
};

template <typename T>
class DoublyLinkedList
{
protected:
    struct DLLNode<T> *head = NULL;
    struct DLLNode<T> *tail = NULL;

public:
    ~DoublyLinkedList()
    {
        DLLNode<T> *node = head;
        while (node != NULL)
        {
            DLLNode<T> *nodeCurrent = node;
            node = node->next;
            delete nodeCurrent;
        }
    }

    bool empty()
    {
        return head == NULL || tail == NULL;
    }

    struct DLLNode<T> *getFront()
    {
        return head;
    }

    void
    pushFront(T key)
    {
        struct DLLNode<T> *newNode = new DLLNode<T>;
        newNode->key = key;
        newNode->next = head;
        newNode->prev = NULL;
        if (empty())
            head = tail = newNode;
        else
            head->prev = newNode;
        head = newNode;
    }

    void popFront()
    {
        if (empty())
            throw;
        head = head->next;
        if (empty())
            tail = NULL;
    }

    struct DLLNode<T> *getBack()
    {
        return tail;
    }

    void
    pushBack(T key)
    {
        struct DLLNode<T> *newNode = new DLLNode<T>;
        newNode->key = key;
        newNode->next = NULL;
        newNode->prev = tail;
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
        tail = tail->prev;
        tail->next = NULL;
        if (empty())
            tail = NULL;
    }

    void insertAfter(struct DLLNode<T> *node, T key)
    {
        struct DLLNode<T> *newNode = new DLLNode<T>;
        newNode->key = key;
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
        if (tail == node)
            tail = newNode;
    }

    void insertBefore(struct DLLNode<T> *node, T key)
    {
        struct DLLNode<T> *newNode = new DLLNode<T>;
        newNode->key = key;
        newNode->next = node;
        newNode->prev = node->prev;
        node->prev->next = newNode;
        node->prev = newNode;
        if (head == node)
            head = newNode;
    }

    struct DLLNode<T> *at(int index)
    {
        int indexCount = 0;
        DLLNode<T> *node = head;
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
        DLLNode<T> *node = head;
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
        DLLNode<T> *node = head;
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
        DLLNode<T> *node = head;
        while (node->next != NULL)
        {
            cout << node->key << " -> ";
            node = node->next;
        }
        cout << node->key << endl;
        cout << "head: " << getFront()->key << endl;
        cout << "tail: " << getBack()->key << endl;
    }
};
