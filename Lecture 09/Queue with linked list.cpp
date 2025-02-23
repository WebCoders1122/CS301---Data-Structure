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

int main()
{
    Queue q;
    int choice;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            cout << "Dequeued element: " << q.dequeue() << endl;
            break;
        case 3:
            cout << "Front element: " << q.front() << endl;
            break;
        case 4:
            q.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}