#include <iostream>
#include "Node.h"
#include <conio.h>
using namespace std;

// doubly linked list
class List
{
public:
    // con and des
    List()
    {
        head = nullptr;
        tail = nullptr;
        currentNode = nullptr;
        size = 0;
    };
    ~List() {};

    // 1.add
    void add(int data)
    {
        Node *newNode = new Node();
        newNode->setData(data);
        if (currentNode == nullptr)
        {
            head = newNode;
            currentNode = newNode;
            tail = newNode;
        }
        else
        {
            Node *nextNode = currentNode->getNext();
            Node *preNode = currentNode;
            if (nextNode == nullptr)
            {
                tail = newNode;
                currentNode->setNext(newNode);
                newNode->setNext(nullptr);
                newNode->setPrev(currentNode);
                currentNode = newNode;
            }
            else
            {
                newNode->setNext(nextNode);
                newNode->setPrev(preNode);
                nextNode->setPrev(newNode);
                preNode->setNext(newNode);
                currentNode = newNode;
            }
        }
        size++;
    };
    // start
    void start()
    {
        currentNode = head;
    };
    void end()
    {
        currentNode = tail;
    };
    // show
    void getCurrent()
    {
        cout << "\nCurrent Node is :" << currentNode->getData() << endl;
    };
    // length
    int length()
    {
        cout << endl
             << "Length is : " << size << endl;
        return size;
    };
    // next
    void next()
    {
        currentNode = currentNode->getNext();
    };
    // back
    void back()
    {
        currentNode = currentNode->getPrev();
    };
    // show all
    void showAll()
    {
        Node *temp = currentNode;
        start();
        for (int i = 0; i < size; i++)
        {
            cout << "Node " << i + 1 << " is : " << currentNode->getData() << endl;
            next();
        }
        currentNode = temp;
    };
    // search
    void search()
    {
        int num;
        cout << "\n\nEnter value to search: ";
        cin >> num;
        if (currentNode == nullptr)
        {
            cout << "\n\nList is empty\n";
        }

        start();
        int found = 0;
        while (currentNode->getNext() != nullptr)
        {
            if (currentNode->getData() == num)
            {
                cout << "\n\nEntered Value Found\n";
                found++;
                break;
            }
            next();
        }
        if (found == 0)
        {
            cout << "\n\nEntered Value Not Found\n";
        }
    }
    // update
    void update()
    {
        int num;
        cout << "\n\nEnter value to update: ";
        cin >> num;
        if (currentNode == nullptr)
        {
            cout << "\n\nList is empty\n";
        }

        start();
        int found = 0, num2 = 0;
        while (currentNode->getNext() != nullptr)
        {
            if (currentNode->getData() == num)
            {
                cout << "\n\nEnter new value: ";
                cin >> num2;
                currentNode->setData(num2);
                cout << "\n\nValue updated successfully\n";
                found++;
                break;
            }
            next();
        }
        if (found == 0)
        {
            cout << "\n\nCan't update value because your entered value is not in the list.\n";
        }
    }
    // delete
    void remove()
    {
        if (currentNode == nullptr)
        {
            cout << "\n\nList is empty\n";
        }
        int num;
        cout << "\n\nEnter value to delete: ";
        cin >> num;
        start();
        // to find node
        int found = 0;
        while (currentNode->getNext() != nullptr)
        {
            if (currentNode->getData() == num)
            {
                found = currentNode->getData();
                break;
            }
            next();
        }
        if (found == 0)
        {
            cout << "\n\nEntered Value Not Found to delete.\n";
        }
        else
        {
            // to delete node
            if (head == tail && head->getData() == num)
            {
                Node *temp = head;
                head = nullptr;
                tail = nullptr;
                delete temp;
            }
            else if (head->getData() == num && currentNode == head)
            {
                Node *nextNode = currentNode->getNext();
                Node *temp = currentNode;
                currentNode = nextNode;
                head = nextNode;
                delete temp;
            }
            else if (tail->getData() == num && currentNode == tail)
            {
                Node *preNode = currentNode->getPrev();
                Node *temp = currentNode;
                currentNode = preNode;
                tail = preNode;
                delete temp;
            }
            else
            {

                // pre cur next
                Node *preNode = currentNode->getPrev();
                Node *nextNode = currentNode->getNext();
                preNode->setNext(nextNode);
                nextNode->setPrev(preNode);
                Node *temp = currentNode;
                currentNode = preNode;
                delete temp;
            }
            size--;
        }
    }

private:
    Node *head;
    Node *tail;
    Node *currentNode;
    int size;
};
int main()
{
    List list;
    int choice;
    do
    {

        cout << "\n\n1.Add\n2.Show All\n3.Show Current\n4.Next\n5.Back\n6.Length\n7.Search\n8.Update\n9.Delete\n0.Exit\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int num;
            cout << "\n\nEnter value to add: ";
            cin >> num;
            list.add(num);
            break;
        case 2:
            list.showAll();
            break;
        case 3:
            list.getCurrent();
            break;
        case 4:
            list.next();
            break;
        case 5:
            list.back();
            break;
        case 6:
            list.length();
            break;
        case 7:
            list.search();
            break;
        case 8:
            list.update();
            break;
        case 9:
            list.remove();
            break;
        case 0:
            cout << "\n\nExiting...\n";
            break;
        default:
            cout << "\n\nInvalid choice\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

/*
 */