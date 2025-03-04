#include <iostream>
#include "TreeNode.h"
using namespace std;
// stack class
class Stack
{
public:
    Stack()
    {
        size = 20;
        current = -1;
    };
    ~Stack() {};
    // utility functions
    // isEmpty & isFull
    bool isEmpty()
    {
        if (current == -1)
            return 1;
        else
            return 0;
    };
    bool isFull()
    {
        if (current == size - 1)
            return 1;
        else
            return 0;
    };
    // push, pop, top
    void push(Node *data)
    {
        if (!isFull())
            Arr[++current] = data;
        else
            cout << "Stack is full. Data not entered." << endl;
    };
    Node *pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Data can't be deleted." << endl;
            return nullptr; // Returning nullptr is correct for an empty stack.
        }
        else
            return Arr[current--];
    };
    Node *top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No Top element found." << endl;
            return nullptr;
        }
        else
            return Arr[current];
    }

private:
    int size;
    int current;
    Node *Arr[20];
};
