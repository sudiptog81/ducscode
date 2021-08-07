#include <iostream>

using namespace std;

template <typename T>
struct SLLNode
{
    T key;
    struct SLLNode *next;
};

template <typename T>
class SinglyLinkedList
{
protected:
    struct SLLNode<T> *head = NULL;
    struct SLLNode<T> *tail = NULL;

public:
    ~SinglyLinkedList()
    {
        SLLNode<T> *node = head;
        while (node != NULL)
        {
            SLLNode<T> *nodeCurrent = node;
            node = node->next;
            delete nodeCurrent;
        }
    }

    bool empty()
    {
        return head == NULL || tail == NULL;
    }

    struct SLLNode<T> *getFront()
    {
        return head;
    }

    void
    pushFront(T key)
    {
        struct SLLNode<T> *newNode = new SLLNode<T>;
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

    struct SLLNode<T> *getBack()
    {
        return tail;
    }

    void
    pushBack(T key)
    {
        struct SLLNode<T> *newNode = new SLLNode<T>;
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
            struct SLLNode<T> *node = head;
            while (node->next->next != NULL)
                node = node->next;
            node->next = NULL;
            tail = node;
        }
    }

    void insertAfter(struct SLLNode<T> *node, T key)
    {
        struct SLLNode<T> *newNode = new SLLNode<T>;
        newNode->key = key;
        newNode->next = node->next;
        node->next = newNode;
        if (tail == node)
            tail = newNode;
    }

    void insertBefore(struct SLLNode<T> *node, T key)
    {
        SLLNode<T> *temp = head;
        while (temp != NULL)
        {
            if (temp->next == node)
            {
                struct SLLNode<T> *newNode = new SLLNode<T>;
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

    struct SLLNode<T> *at(int index)
    {
        int indexCount = 0;
        SLLNode<T> *node = head;
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
        SLLNode<T> *node = head;
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
        SLLNode<T> *node = head;
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
        SLLNode<T> *node = head;
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
