#include <iostream>
#include "circular linked list.cpp"
using namespace std;
int main()
{
    // for adding 10 numbers
    List list;
    for (int i = 1; i <= 10; i++)
    {
        list.add(i);
    }
    list.show();
    cout << endl;
    list.start();

    while (list.length() > 1)
    {

        for (int j = 0; j <= 2; j++)
        {
            list.next();
        }
        list.remove();
    }
    list.show();

    return 0;
}