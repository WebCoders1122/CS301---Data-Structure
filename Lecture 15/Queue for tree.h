#include "TreeNode.h"
template <class T>
class Queue
{
private:
    int noElements;
    int front;
    int rear;
    Node<T> *arr[100];

public:
    Queue()
    {
        noElements = 0;
        front = -1;
        rear = -1;
    };
    ~Queue() {};
    // utility functions
    bool isEmpty()
    {
        return noElements == 0;
    }
    bool isFull()
    {
        return noElements == 100;
    }
    void enqueue(Node<T> *data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % 100;
        arr[rear] = data;
        noElements++;
    }
    Node<T> *dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return nullptr; // Corrected to return nullptr for an empty queue.
        }
        Node<T> *data = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % 100;
        }
        noElements--;
        return data;
    }
    Node<T> *frontElem()
    {
        return arr[front];
    }
    Node<T> *rearElem()
    {
        return arr[rear];
    }
};
