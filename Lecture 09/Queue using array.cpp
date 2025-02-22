#include <iostream>
using namespace std;
// Queue class
class Queue
{
private:
    /* data */
    int arr[10];
    int first, rear, size, noElements;

public:
    Queue()
    {
        first = -1;
        rear = -1;
        size = 10;
        noElements = 0;
    };
    ~Queue() {};
    // utility functions
    bool isEmpty()
    {
        return noElements == 0;
    };
    bool isFull()
    {
        return noElements == size;
    };
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            first = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = data;
        noElements++;
    };
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int temp = arr[first];
        first = (first + 1) % size;
        noElements--;
        return temp;
    };
    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[first];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int temp = first;
        while (temp != rear)
        {
            cout << arr[temp] << endl;
            temp = (temp + 1) % size;
        }
        cout << arr[temp] << endl;
    }
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