#include <iostream>
#include "Node.h"
using namespace std;
class PriorityQueue
{
private:
    Node *head;
    Node *tail;
    int noElements;

public:
    PriorityQueue()
    {
        head = nullptr;
        tail = nullptr;
        noElements = 0;
    };
    ~PriorityQueue() {};
    // utility functions
    bool isEmpty();
    int length();
    void enqueue(int data);
    int dequeue();
    void display();
    int front();
    int rear();
    void sortPQ();
};
// definition of functions
bool PriorityQueue::isEmpty()
{
    return head == nullptr;
};
int PriorityQueue::length()
{
    return noElements;
};
void PriorityQueue::enqueue(int data)
{
    Node *newNode = new Node;
    newNode->setData(data);
    newNode->setNext(nullptr);
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
        noElements++;
    }
    else
    {
        tail->setNext(newNode);
        tail = newNode;
        noElements++;
        sortPQ();
    }
};
int PriorityQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    Node *temp = head;
    int data = temp->getData();
    head = head->getNext();
    noElements--;
    delete temp;
    return data;
};
void PriorityQueue::display()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->getData() << endl;
        temp = temp->getNext();
    };
};
int PriorityQueue::front()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return head->getData();
};
int PriorityQueue::rear()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return tail->getData();
};
void PriorityQueue::sortPQ()
{
    int temp;
    for (int i = 0; i < noElements; i++)
    {
        Node *ptr = head;
        for (int j = 0; j < noElements - 1; j++)
        {
            if (ptr->getData() < ptr->getNext()->getData())
            {
                temp = ptr->getData();
                ptr->setData(ptr->getNext()->getData());
                ptr->getNext()->setData(temp);
            }
            if (ptr->getNext() != nullptr)
            {
                ptr = ptr->getNext();
            }
        }
    }
};