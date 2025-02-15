#include<stdlib.h>

class Node
{
public:
    // constructor and destructor
    Node()
    {
        int data = 0;
        next = nullptr;
        prev = nullptr;
    };
    ~Node() {};
    // getters and setters
    int getData()
    {
        return data;
    };

    Node *getNext()
    {
        return next;
    };
    Node *getPrev()
    {
        return prev;
    };

    void setData(int data)
    {
        this->data = data;
    };
    void setNext(Node *next)
    {
        this->next = next;
    };
    void setPrev(Node *prev)
    {
        this->prev = prev;
    };

private:
    int data;
    Node *next;
    Node *prev;
};
