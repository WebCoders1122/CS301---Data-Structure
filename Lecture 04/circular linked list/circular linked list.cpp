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
    void add()
    {
        // creating new node
        Node *newNode = new Node();
        // taking use input
        int value;
        cout << "Enter value to add to list: ";
        cin >> value;
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
        if (current == nullptr)
        {
            cout << "\nList is empty\n\n";
        }
        int value, match;
        cout << "Enter value to remove from list: ";
        cin >> value;
        start();
        while (current->getNext() != head) // loop through the list
        {
            if (value == current->getData())
            {
                match = value;
                break;
            }
            next();
        };

        if (head == tail && head->getData() == match) // only one node in the list
        {
            Node *ptr = head;
            head = nullptr;
            tail = nullptr;
            current = nullptr;
            lastCurrent = nullptr;
            delete ptr;
            size--;
        }
        else if (head->getData() == match) // if the first node is to be removed
        {
            Node *ptr = head;
            head = head->getNext();
            tail->setNext(head);
            delete ptr;
            size--;
        }
        else if (tail->getData() == match) // if the last node is to be removed
        {
            start();
            while (current->getNext() != head)
            {
                next();
            }
            Node *ptr = tail;
            tail = lastCurrent;
            tail->setNext(head);
            delete ptr;
            size--;
        }
        else // if any other node is to be removed
        {
            Node *ptr = current;
            lastCurrent->setNext(current->getNext());
            current = current->getNext();
            delete ptr;
            size--;
        }
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
int main()
{
    List list;
    int choice;
    do
    {
        cout << "\n1. Add\n2. Remove\n3. Show\n4. Get Current\n5. Next\n6. Start\n7. Length\n0. Exit\n\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            list.add();
            break;
        }
        case 2:
        {
            list.remove();
            break;
        }
        case 3:
        {
            list.show();
            break;
        }
        case 4:
        {
            cout << "Current: " << list.getCurrent() << endl;
            break;
        }
        case 5:
        {
            list.next();
            break;
        }
        case 6:
        {
            list.start();
            break;
        }
        case 7:
        {
            cout << "Length: " << list.length() << endl;
            break;
        }
        case 0:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}