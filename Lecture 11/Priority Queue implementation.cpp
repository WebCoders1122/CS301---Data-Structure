#include <iostream>
#include "PriorityQueue.h"
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
        cout << "6. IsFull" << endl;
        cout << "7. Front" << endl;
        cout << "8. Rear" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            pq.insert(data);
            break;
        case 2:
            pq.remove();
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
            pq.isFull();
            break;
        case 7:
            cout << "Front: " << pq.front() << endl;
            break;
        case 8:
            cout << "Rear: " << pq.last() << endl;
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