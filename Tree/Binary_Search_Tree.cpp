//
// Author: Sharath Lokesh
//

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;

    // Recursively remove nodes in tree
    void remove(Node *currentNode)
    {
        if (currentNode->left) remove(currentNode->left);
        if (currentNode->right) remove(currentNode->right);
        delete currentNode;
    }

public:
    BST(): root(nullptr) {}
    
    ~BST()
    {
        remove(root);
    }
    
    

    // Insert node
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr) 
        {
            root = newNode;
            return;
        }

        Node *temp = root;

        while(true) 
        {
            if (newNode->data == temp->data) return;
            if (newNode->data < temp->data) 
            {
                if (nullptr == temp->left) 
                {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            } 
            else 
            {
                if (nullptr == temp->right) 
                {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    // Search node
    bool search(int value)
    {
        Node *temp = root;
        while(nullptr != temp) 
        {
            if (value == temp->data) return true;
            if (value < temp->data) temp = temp->left;
            else temp = temp->right;
        }
        return false;
    }    
};

int main()
{
    BST tree;

    tree.insert(5); 
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << boolalpha;
    cout << tree.search(5) << endl;
    cout << tree.search(9) << endl;


    return 0;
}