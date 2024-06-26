/**
* Author: Sharath Lokesh
*/

#include <iostream>
#include <limits>
using namespace std;

// Queue using Linked List
template<typename T1>
class Node
{
public:
    T1 data;
    Node<T1> *next;
    Node(T1 data)
    {
        this->data = data;
        next = nullptr;
    }
};

template<typename T>
class MyQueue
{
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    MyQueue(): head(nullptr), tail(nullptr), length(0) {}
    MyQueue(int value) {
        Node<T> *newNode = new Node<int>(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~MyQueue() {
        Node<T> *temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    // print queue
    void printQueue() {
        Node<T> *temp = head;
        cout<<"[";
        while (temp != nullptr) {
            cout << temp->data;
            if (nullptr!= temp->next)
                cout<< ",";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    // getters
    Node<T>* getHead() const { return head; }
    Node<T>* getTail() const { return tail; }
    int getLength() const { return length; }

    // add element to queue
    void addElement(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // remove element from queue
    T removeElement() {
        if (head == nullptr) return std::numeric_limits<T>::min();
        T retVal = head -> data;
        Node<T> *temp = head;
        if (head == tail) {
            // delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
        length--;
        return retVal;
    }
};

int main() {
    MyQueue<int> q(10);
    q.addElement(5);
    q.addElement(20);
    q.printQueue();
    cout<<q.removeElement()<<endl;
    q.printQueue();
    cout<<q.getLength()<<endl;

    MyQueue <char> q2;

    q2.printQueue();
    cout<<q2.getLength()<<endl;
    cout<<q2.removeElement()<<endl;
    q2.addElement('a');
    q2.printQueue();

    return 0;
}