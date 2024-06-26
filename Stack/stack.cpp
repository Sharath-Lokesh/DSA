/**
* Author: Sharath Lokesh
*/

#include<iostream>
#include<limits>
using namespace std;

// Node Class
//
// This class is used to create a node in the stack
template<typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T d): data(d), next(nullptr) {}
};

// Stack Class
//
// This class is used to create a stack
template<typename T>
class MyStack
{
private:
    Node<T> *top;
    int length;

public:
    // Constructor
    //
    // This function is used to create a stack
    MyStack(): top(nullptr), length(0) {}
    MyStack(T value): top(new Node<T>(value)), length(1) {}

    // Destructor
    //
    // This function is used to delete the stack
    ~MyStack() {
        Node<T> *temp = top;
        while (nullptr == top) {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    // Print Stack
    //
    // This function is used to print the stack
    void printStack() {
        Node<T> *temp = top;
        cout << "[";
        while (nullptr != temp) {
            cout << temp->data;
            if(nullptr != temp->next) 
                cout<< ",";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    // Get Top
    //
    // This function is used to get the top of the stack
    Node<T> *getTop() {
        return top;
    }

    // Get Length
    //
    // This function is used to get the length of the stack
    int getLength() {
        return length;
    }

    // Push
    //
    // This function is used to push an element to the stack
    void push(T value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        length++;
    }

    // Pop
    //
    // This function is used to pop an element from the stack
    T pop() {
        if (length == 0) return std::numeric_limits<T>::min();

        Node<T> *temp = top;
        T poppedValue = top->data;
        top = top->next;
        delete temp;
        length--;
        return poppedValue;
    }
};

int main() {
    MyStack<int> stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.printStack();
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    stack.printStack();
    cout << stack.getLength() << endl;
    cout << stack.getTop()->data << endl;

    MyStack<char> stack2('a');
    cout << stack2.pop() << endl;
    cout << stack2.pop() << endl;
    
    return 0;
}