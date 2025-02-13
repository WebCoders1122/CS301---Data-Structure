#include <iostream>
#include "Node.h"
using namespace std;

// doubly linked list
class List
{
public:
    // con and des
    List()
    {
        head = nullptr;
        tail = nullptr;
        currentNode = nullptr;
        lastCurrentNode = nullptr;
        size = 0;
    };
    ~List() {};

    // add
    void add(int data)
    {
        Node *newNode = new Node();
        newNode->setData(data);
        if (currentNode == nullptr)
        {
            head = newNode;
            currentNode = newNode;
            lastCurrentNode = nullptr;
        }
        else
        {
            newNode->setNext(currentNode->getNext());
            newNode->setPrev(currentNode);
            if (currentNode->getNext() != nullptr)
            {
                (currentNode->getNext())->setPrev(newNode);
            }
            currentNode->setNext(newNode);
            lastCurrentNode = currentNode;
            currentNode = newNode;
        }
        size++;
    };
    // start
    void start()
    {
        lastCurrentNode = nullptr;
        currentNode = head;
    };
    // show
    int get()
    {
        return currentNode->getData();
    };

private:
    Node *head;
    Node *tail;
    Node *currentNode;
    Node *lastCurrentNode;
    int size;
};
int main()
{

    List list;
    list.add(1);
    int x = list.get();
    cout << x << endl;
    list.add(2);

    x = list.get();
    cout << x << endl;
    list.start();
    x = list.get();

    cout << x << endl;

    return 0;
}