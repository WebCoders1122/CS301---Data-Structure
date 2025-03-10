#include <iostream>
// #include "TreeNode.h"
#include "Stack with array.cpp"
#include "Queue for tree.h"
using namespace std;
void insert(Node *, int);
void preorder(Node *);
void inorder(Node *);
void postorder(Node *);
void levelOrder(Node *);
int main()
{
    int numbers[] = {3, 7, 2, 7, 4, 9, 2, 5, 9, 1, 8, 4, 6, 5, 10};
    // creating root node
    Node *root = new Node;
    root->setInfo(numbers[0]);
    // inserting alll other nodes from array
    for (int i = 1; numbers[i] > 0; i++)
    {
        insert(root, numbers[i]);
    };
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nLevel Order: ";
    levelOrder(root);
    return 0;
}

// define insert function
void insert(Node *root, int value)
{
    Node *newNode = new Node;
    newNode->setInfo(value);

    Node *q = root;
    Node *p = root;

    // Find the correct position to insert
    while (value != (p->getInfo()) && q != nullptr)
    {
        p = q;

        if (value > p->getInfo())
        {
            q = p->getRight();
        }
        else if (value < p->getInfo())
        {
            q = p->getLeft();
        }
    }

    // Insert the new node at the correct position
    if (value == p->getInfo())
    {
        cout << "\nDuplicate Value\n";
        delete newNode;
        return;
    }
    else if (value < p->getInfo())
    {
        p->setLeft(newNode);
    }
    else
    {
        p->setRight(newNode);
    }
};
// functions to print the tree with recursion calls
void preorder(Node *treeNode)
{
    if (treeNode != nullptr)
    {
        cout << treeNode->getInfo() << " ";
        preorder(treeNode->getLeft());
        preorder(treeNode->getRight());
    }
};
// void inorder(Node *treeNode)
// {
//     if (treeNode != nullptr)
//     {
//         inorder(treeNode->getLeft());
//         cout << treeNode->getInfo() << " ";
//         inorder(treeNode->getRight());
//     }
// }
void postorder(Node *treeNode)
{
    if (treeNode != nullptr)
    {
        postorder(treeNode->getLeft());
        postorder(treeNode->getRight());
        cout << treeNode->getInfo() << " ";
    }
}
// functions to print the tree without recursion calls
void inorder(Node *treeNode)
{
    Stack stack;
    Node *temp = treeNode;
    // this do while loop will run until the stack is empty and the temp is not nullptr pushing all nodes in the stack
    do
    {
        // this while loop will push all the left nodes in the stack
        while (temp != nullptr)
        {
            stack.push(temp);
            temp = temp->getLeft();
        }
        // this will pop the last node from the stack and print it
        if (!stack.isEmpty())
        {
            temp = stack.pop();
            cout << temp->getInfo() << " ";
            temp = temp->getRight();
        }

    } while (!stack.isEmpty() || temp != nullptr);
}
// level order traversal
void levelOrder(Node *root)
{
    Queue q;
    Node *node = root;
    q.enqueue(node);

    while (!q.isEmpty())
    {
        cout << node->getInfo() << " ";
        node = q.dequeue();
        if (node->getLeft() != nullptr)
        {
            q.enqueue(node->getLeft());
        }
        if (node->getRight() != nullptr)
        {
            q.enqueue(node->getRight());
        }
    }
};
