#include <iostream>
using namespace std;
// function 1 with call by value
int intMinus1(int a)
{
    a = a - 1;
    return a;
}
// call by reference
int intMinus2(int *a)
{
    *a = *a - 2;
    return *a;
};
// call with reference variable
int intMinus3(int &a)
{
    a = a - 3;
    return a;
};
int main()
{
    int a = 10, b = 10, c = 10;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    intMinus1(a);
    intMinus2(&b);
    intMinus3(c);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    return 0;
}