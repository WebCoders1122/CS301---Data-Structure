#include <iostream>
#include "Node.h"
using namespace std;

// Queue class
class Queue
{
private:
    Node *head;
    Node *rear;
    int noElements;

public:
    Queue()
    {
        head = nullptr;
        rear = nullptr;
        noElements = 0;
    };
    ~Queue() {};
    // utility functions
    bool isEmpty()
    {
        return head == nullptr;
    };
    void enqueue(int data)
    {
        Node *newNode = new Node();
        newNode->setData(data);
        newNode->setNext(nullptr);
        if (isEmpty())
        {
            head = newNode;
            rear = newNode;
        }
        else
        {
            rear->setNext(newNode);
            rear = newNode;
        }
        noElements++;
    };
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        };
        Node *temp = head;
        head = head->getNext();
        int data = temp->getData();
        delete temp;
        noElements--;
        return data;
    };

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
            return head->getData();
    };
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->getData() << endl;
            temp = temp->getNext();
        }
    };
};
