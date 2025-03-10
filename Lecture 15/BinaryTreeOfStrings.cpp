#include <iostream>
#include <cstring>
#include "Stack with array.cpp"
#include "Queue for tree.h"
using namespace std;
void insert(Node<string> *, string);
void preorder(Node<string> *);
void inorder(Node<string> *);
void postorder(Node<string> *);
void levelOrder(Node<string> *);
int main()
{
    const char *word[] = {"babble", "fable", "jacket",
                          "backup", "eagle", "daily", "gain", "bandit", "abandon",
                          "abash", "accuse", "economy", "adhere", "advise", "cease",
                          "debunk", "feeder", "genius", "fetch", "chain", nullptr};
    // creating root node
    Node<string> *root = new Node<string>;
    root->setInfo(word[0]);

    // inserting all other nodes from array
    for (int i = 1; word[i] != nullptr; i++)
    {
        insert(root, word[i]);
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
void insert(Node<string> *root, string value)
{
    Node<string> *newNode = new Node<string>;
    newNode->setInfo(value);

    Node<string> *q = root;
    Node<string> *p = root;

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
void preorder(Node<string> *treeNode)
{
    if (treeNode != nullptr)
    {
        cout << treeNode->getInfo() << " ";
        preorder(treeNode->getLeft());
        preorder(treeNode->getRight());
    }
};
// void inorder(Node<string> *treeNode)
// {
//     if (treeNode != nullptr)
//     {
//         inorder(treeNode->getLeft());
//         cout << treeNode->getInfo() << " ";
//         inorder(treeNode->getRight());
//     }
// }
void postorder(Node<string> *treeNode)
{
    if (treeNode != nullptr)
    {
        postorder(treeNode->getLeft());
        postorder(treeNode->getRight());
        cout << treeNode->getInfo() << " ";
    }
}
// functions to print the tree without recursion calls
void inorder(Node<string> *treeNode)
{
    Stack stack;
    Node<string> *temp = treeNode;
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
void levelOrder(Node<string> *root)
{
    Queue<string> q;
    Node<string> *node = root;
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
