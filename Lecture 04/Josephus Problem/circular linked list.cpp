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
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        lastCurrent = nullptr;
        size = 0;
    };
    ~List() {

    };
    // other methods
    // add method
    void add(int a)
    {
        // creating new node
        Node *newNode = new Node();
        // taking use input
        int value = a;
        newNode->setData(value);
        // if list is empty --> i.e. 1st node
        if (current == nullptr)
        {
            head = newNode;
            tail = newNode;
            current = newNode;
            lastCurrent = newNode;
            tail->setNext(newNode);
        }
        // if list is not empty
        else
        {
            newNode->setNext(head);
            tail->setNext(newNode);
            lastCurrent = tail;
            tail = newNode;
            current = newNode;
        }
        size++;
    };
    // get method -> to get current position of pointer
    int getCurrent()
    {
        return current->getData();
    };
    // next method
    void next()
    {
        if (current == nullptr)
        {
            cout << "\nList is empty\n\n"
                 << endl;
        }
        else
        {
            lastCurrent = current;
            current = current->getNext();
        }
    };
    // start method
    void start()
    {
        if (current == nullptr)
            cout << "\nList is empty\n\n";
        else
        {
            current = head;
            lastCurrent = head;
        }
    }
    // remove method
    void remove()
    {
        cout << "Deleting " << current->getData() << "\n";
        if (current == nullptr)
        {
            cout << "\nList is empty\n\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = current = lastCurrent = nullptr;
        }
        else if (current == head)
        {
            head = current->getNext();
            tail->setNext(head);
            delete current;
            current = head;
            lastCurrent = tail;
        }
        else if (current == tail)
        {
            tail = lastCurrent;
            tail->setNext(head);
            delete current;
            current = head;
        }
        else
        {
            Node *preNode = lastCurrent;
            Node *nextNode = current->getNext();
            preNode->setNext(nextNode);
            Node *temp = current;
            current = current->getNext();
            delete temp;
        }
        size--;
    };
    // length
    int length()
    {
        return size;
    };
    // show
    void show()
    {
        start();
        do
        {
            cout << "--> " << current->getData() << endl;
            next();
        } while (current != head);
    }

private:
    Node *head;
    Node *tail;
    Node *current;
    Node *lastCurrent;
    // to determine the size of list
    int size;
};