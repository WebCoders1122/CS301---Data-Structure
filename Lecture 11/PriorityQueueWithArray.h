#include <iostream>
#include "BubbleSort.h"
using namespace std;
#define MAXPQ 30
class PriorityQueue
{
private:
    int arr[MAXPQ];
    int first, rear, noElements;

public:
    PriorityQueue()
    {
        first = -1;
        rear = -1;
        noElements = 0;
    };
    ~PriorityQueue() {};
    // utility functions
    bool isEmpty();
    bool isFull();
    // adding data
    void insert(int data);
    int remove();
    int front();
    int last();
    void display();
    void length();
};

bool PriorityQueue::isEmpty()
{
    return noElements == 0;
};
bool PriorityQueue::isFull()
{
    return (noElements == MAXPQ);
}
void PriorityQueue::insert(int data)
{
    if (isFull())
    {
        cout << "Queue is full" << endl;
        return;
    };
    if (isEmpty())
    {
        first = 0;
    }

    arr[noElements] = data;
    noElements++;
    rear = (rear + 1) % MAXPQ;
    // sorting
    sort(arr, noElements);
}
int PriorityQueue::remove()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int temp = arr[first];
    first = (first + 1) % MAXPQ;
    return temp;
}
int PriorityQueue::front()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return arr[first];
}
void PriorityQueue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = first; i < noElements; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}
void PriorityQueue::length()
{
    cout << "Length of queue is " << noElements << endl;
}
int PriorityQueue::last()
{
    cout << "Rear is " << rear << endl;
    return arr[rear];
}