#include <iostream>
// #include "PriorityQueueWithArray.h"
#include "PriorityQueueWithLinkedList.h"
using namespace std;
int main()
{
    int choice;
    PriorityQueue pq;
    do
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Size" << endl;
        cout << "5. IsEmpty" << endl;
        cout << "6. Front" << endl;
        cout << "7. Rear" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            pq.enqueue(data);
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            pq.length();
            break;
        case 5:
            pq.isEmpty();
            break;
        case 6:
            cout << "Front: " << pq.front() << endl;
            break;
        case 7:
            cout << "Rear: " << pq.rear() << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        /* code */
    } while (choice != 0);

    return 0;
}