#include <iostream>
using namespace std;
// node class

class Node
{
private:
    int data;
    Node *nextNode;

public:
    int get()
    {
        return data;
    }
    void set(int data)
    {
        this->data = data;
    }

    Node *getNextNode()
    {
        return nextNode;
    }
    void setNextNode(Node *nextNode)
    {
        this->nextNode = nextNode;
    }
};

int main()
{

    return 0;
}
