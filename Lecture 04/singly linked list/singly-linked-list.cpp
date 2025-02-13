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
    };
    // start method
    void start()
    {
        if (currentNode == NULL)
            cout << "\nList is empty\n\n";
        else
        {
            lastCurrentNode = head;
            currentNode = head;
        }
    }
    // remove method
    void remove()
    {
        if (currentNode == NULL)
        {
            cout << "\nList is empty\n\n";
        }
        else if (currentNode != head)
        {
            lastCurrentNode->setNext(currentNode->getNext());
            currentNode = lastCurrentNode; // todo: what will happen to the last current node
            delete currentNode;
            size--;
        }
    };
    // length
    int length()
    {
        return size;
    };

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
    list.add(87);
    list.add(5);
    list.add(112);
    list.add(6);
    list.start();
    for (int i = 0; i < 5; i++)
    {
        int x = list.get();
        cout << x << endl;
        list.next();
    }

    return 0;
}