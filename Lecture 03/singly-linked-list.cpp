#include <iostream>
#include <stdlib.h>
#include "Node.h"
using namespace std;
// singly linked list class
class List
{
public:
    // constructor and destructors
    List()
    {
        head = new Node();
        head->setNext(NULL);
        currentNode = NULL;
        lastCurrentNode = NULL;
        size = 0;
    };
    ~List() {

    };
    // other methods
    // add method
    void add(int value)
    {
        // creating new node
        Node *newNode = new Node();
        newNode->setData(value);
        // if list is empty --> i.e. 1st node
        if (currentNode == NULL)
        {
            head->setNext(newNode);
            newNode->setNext(NULL);
            currentNode = newNode;
        }
        // if list is not empty
        else
        {
            newNode->setNext(currentNode->getNext());
            currentNode->setNext(newNode);
            lastCurrentNode = currentNode;
            currentNode = newNode;
        }
        size++;
    };
    // get method -> to get current position of pointer
    int get()
    {
        return currentNode->getData();
    };
    // next method
    void next()
    {
        if (currentNode == NULL)
        {
            cout << "\nList is empty\n\n"
                 << endl;
        }
        else if (currentNode->getNext() == NULL)
        {
            cout << "\nList has no next element\n\n"
                 << endl;
        }
        else
        {
            lastCurrentNode = currentNode;
            currentNode = currentNode->getNext();
        }
    }

private:
    Node *head;
    Node *currentNode;
    Node *lastCurrentNode;
    // to determine the size of list
    int size = 0;
};
int main()
{
    List list;
    list.add(2);
    list.add(3);
    int x = list.get();
    cout << x << endl;
    list.next();
    cout << x << endl;

    return 0;
}