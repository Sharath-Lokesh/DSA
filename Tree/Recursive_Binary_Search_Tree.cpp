//
// Author: Sharath Lokesh
//

#include <iostream>
#include <limits>

using namespace std;

// Node Class
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

class rBST
{
private:
    Node *root;

    // Recursively search node
    bool rSearch(Node *CurrentNode, int value)
    {
        if (nullptr == CurrentNode) 
            return false;

        if (value == CurrentNode->data) 
            return true;
        if (value < CurrentNode->data) 
            return rSearch(CurrentNode->left, value);
        if (value > CurrentNode->data) 
            return rSearch(CurrentNode->right, value);
    }

    // Recursively insert node
    Node* rInsert(Node *CurrentNode, int value)
    {
        if (nullptr == CurrentNode) 
            return new Node(value);

        if (value < CurrentNode->data) 
            CurrentNode->left = rInsert(CurrentNode->left, value);
        if (value > CurrentNode->data) 
            CurrentNode->right = rInsert(CurrentNode->right, value);

        return CurrentNode;
    }

    // Recursively delete node
    Node* rDelete(Node *CurrentNode, int value)
    {
        if (nullptr == CurrentNode)
            return nullptr;
        if (value < CurrentNode->data)
            CurrentNode->left = rDelete(CurrentNode->left, value);
        else if (value > CurrentNode->data)
            CurrentNode->right = rDelete(CurrentNode->right, value);
        else
        {
            if (nullptr == CurrentNode->left && nullptr == CurrentNode->right)
                {
                    delete CurrentNode;
                    return nullptr;
                }
            else if (nullptr == CurrentNode->left)
                {
                    Node* temp = CurrentNode->right;
                    delete CurrentNode;
                    return temp;
                }  
            else if (nullptr == CurrentNode->right)
                {
                    Node* temp = CurrentNode->left;
                    delete CurrentNode;
                    return temp;
                }
            else
            {
                int Min = rMin(CurrentNode->right);
                CurrentNode->data = Min;
                CurrentNode->right = rDelete(CurrentNode->right, Min);
            }
        }
        return CurrentNode;
    }

    // Recursively remove nodes in tree
    void remove(Node *currentNode)
    {
        if (currentNode->left) remove(currentNode->left);
        if (currentNode->right) remove(currentNode->right);
        delete currentNode;
    }

    // Return min value
    int rMin(Node *CurrentNode)
    {
        if (nullptr == CurrentNode) 
            return numeric_limits<int>::max();
        if (nullptr == CurrentNode->left) 
            return CurrentNode->data;
        return rMin(CurrentNode->left);
    }

    // Return max value
    int rMax(Node *CurrentNode)
    {
        if (nullptr == CurrentNode) 
            return numeric_limits<int>::min();
        if (nullptr == CurrentNode->right) 
            return CurrentNode->data;
        return rMax(CurrentNode->right);
    }


public:
    rBST(): root(nullptr) {}

    ~rBST()
    {
        remove(root);
    }
    // Insert node
    void rInsert(int value)
    {
        Node *newNode = new Node(value);
    
        if (nullptr == root) 
        {
            root = newNode;
            return;
        }
        rInsert(root, value);
    }

    // Search node
    bool rSearch(int value)
    {
        return rSearch(root, value);
    }

    
    // Delete node
    void rDelete(int value)
    {
        root = rDelete(root, value);
    }

    // Return min value
    int rMin()
    {
        return rMin(root);
    }
    
    // Return max value
    int rMax()
    {
        return rMax(root);
    }
};

int main()
{
    rBST myBST;
    cout << boolalpha;
    myBST.rInsert(5);
    myBST.rInsert(3);
    myBST.rInsert(7);
    myBST.rInsert(2);
    myBST.rInsert(4);
    myBST.rInsert(6);
    myBST.rInsert(8);


    cout << "Contains 5: " << myBST.rSearch(5);
    cout << "\n\nContains 9: " << myBST.rSearch(9);

    cout << "\n\nMin: " << myBST.rMin();
    cout << "\n\nMax: " << myBST.rMax();

    myBST.rDelete(5);

    cout << "\n\nContains 5: " << myBST.rSearch(5);

    return 0;
}