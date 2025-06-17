#include <iostream>
#include <string>
#include "BSTNode.h"
using namespace std;
int main()
{
    // string of names to be inserted in binary tree
    string names[] = {"Saleh", "Ali", "Umar", "Musaddiq", "Rehman", "Hassaan"};
    cout << "Inserting names into binary tree one by one" << endl;
    cout << "--------------------------------------------" << endl;
    int treeData[6];
    // loop to calculate the length of each name in array
    for (int i = 0; i < 6; i++)
    {
        treeData[i] = names[i].length();
        cout << "Length of " << names[i] << " is: " << treeData[i] << endl;
    }

    return 0;
}