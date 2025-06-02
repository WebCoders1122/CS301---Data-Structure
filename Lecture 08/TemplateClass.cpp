#include <iostream>
#include <string>
using namespace std;
// templete is generic data type, used to create a class or function that can work with any data type
// making a generic functions
template <class T>
void printValue(T value)
{
    cout << "Value: " << value << endl;
}
// using template with class
template <class T>
class Stack
{
private:
    T a, b;

public:
    Stack(/* args */) {};
    ~Stack() {};
    void inputA(T a);
    void inputB(T b);
    void display();
};
// if we defince class function out of the class then we need to declare template type before the function name
template <class T>
void Stack<T>::inputA(T a)
{
    this->a = a;
};
template <class T>
void Stack<T>::inputB(T b)
{
    this->b = b;
};
template <class T>
void Stack<T>::display()
{
    cout << "Stack values: " << a << ", " << b << endl;
}

int main()
{
    // generic data type function accepts all data types
    printValue(5);               // int
    printValue(3.14);            // double
    printValue("Hello, World!"); // string
    // using template with class
    Stack<int> intStack;
    intStack.inputA(10);
    intStack.inputB(20);
    intStack.display();
    Stack<string> stringStack;
    stringStack.inputA("Hello");
    stringStack.inputB("World");
    stringStack.display();
    return 0;
}