#include <iostream>
using namespace std;
// node class

class Node
{
public:
    // constructor and destructor
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    };
    ~Node() {};
    // getters and setters
    int getData()
    {
        return data;
    }
    void setData(int data)
    {
        this->data = data;
    }

    Node *getNext()
    {
        return next;
    }
    void setNext(Node *nextNode)
    {
        this->next = nextNode;
    }

private:
    int data;
    Node *next;
};