#include <iostream>
using namespace std;
// stack class
class Stack
{
public:
    Stack()
    {
        size = 10;
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
    void push(int data)
    {
        if (!isFull())
            Arr[++current] = data;
        else
            cout << "Stack is full. Data not entered." << endl;
    };
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Data can't be deleted." << endl;
            return -1;
        }
        else
            return Arr[current--];
    };
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No Top element found." << endl;
            return -1;
        }
        else
            return Arr[current];
    }

private:
    int size;
    int current;
    int Arr[10];
};
int main()
{
    Stack stack;
    bool empty = stack.isEmpty();
    cout << "Is stack empty: " << empty << endl;
    for (int i = 1; i <= 10; i++)
    {
        stack.push(i);
    };
    cout << "Top element: " << stack.top() << endl;
    // int poped = stack.pop();
    // cout << "Poped element: " << poped << endl;
    // int current = stack.top();
    // cout << "Current element: " << current << endl;

    bool full = stack.isFull();
    cout << "Is stack full: " << full << endl;

    return 0;
}