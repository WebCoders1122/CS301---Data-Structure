#include <iostream>
#include "Node.h"
using namespace std;
class Stack
{
public:
    // constructor and destructor
    Stack()
    {
        head = nullptr;
    }
    ~Stack()
    {

        while (!isEmpty())
        {
            pop();
        }
    }
    // other functions
    bool isEmpty()
    {
        return (head == nullptr);
    };
    void push(int newData)
    {
        Node *newNode = new Node();
        newNode->setData(newData);
        newNode->setNext(head);
        head = newNode;
    };
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            Node *temp = head;
            int data = temp->getData();
            head = head->getNext();
            delete temp;
            return data;
        }
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return head->getData();
        }
    };
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->getData() << endl;
            temp = temp->getNext();
        }
        cout << endl;
    }

private:
    Node *head;
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    s.pop();
    cout << endl;
    s.display();
    cout << s.top() << endl;

    return 0;
}