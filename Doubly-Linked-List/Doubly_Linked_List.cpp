/**
* Author: Sharath Lokesh
*/

#include<iostream>

using namespace std;

template <typename T1>
class Node
{
    public:
    T1 data;
    Node<T1> *next;
    Node<T1> *prev;

    // Constructs a new Node object with the given data.
    // 
    // @param d the data to be stored in the Node
    Node(T1 d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList
{
    private:
    Node<T> *head;
    Node<T> *tail;
    int length;

    public:

    // Constructs a new DoublyLinkedList object.
    DoublyLinkedList(): head(nullptr), tail(nullptr), length(0) {}
    // Constructs a new Node object with the given data.
    //
    // @param d the data to be stored in the Node
    DoublyLinkedList(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    // Destructor that deletes all the nodes in the list.
    ~DoublyLinkedList()
    {
        Node<T> *temp = head;
        while (nullptr != head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    // Returns the length of the list.
    int getLength() const { return length; }

    // Returns the head of the list.
    Node<T> *getHead() const { return head; }

    // Returns the tail of the list.
    Node<T> *getTail() const { return tail; }

    // Prints the data of all the nodes in the list.
    void printList()
    {
        Node<T> *temp = head;
        cout << "[";
        while (temp != nullptr)
        {
            cout << temp->data;
            if (nullptr != temp->next)
                cout << ", ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    // Adds a new node with the given data to the back of the list.
    //
    // @param value the data to be stored in the new node
    void addBack(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (nullptr == head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    // Adds a new node with the given data to the front of the list.
    //
    // @param value the data to be stored in the new node
    void addFront(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (nullptr == head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    // Removes the node at the front of the list.
    void removeFront()
    {
        if (nullptr == head)
            return;
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        length--;
    }

    // Removes the node at the back of the list.
    void removeBack()
    {
        if (nullptr == head)
            return;
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node<T> *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        length--;
    }

    // Returns the node at the given index.
    // 
    // @param index the index of the node
    // @return the node at the given index
    Node<T>* getNode(int index)
    {
        if (index < 0 || index >= length) return nullptr;
        Node<T> *temp = nullptr;
        if (index < length / 2)
        {
            temp = head;
            for (int i = 0; i < index; ++i)
                temp = temp->next;
        }
        else
        {
            temp = tail;
            for (int i = length - 1; i > index; --i)
                temp = temp->prev;
        }
        return temp;
    }

    // Sets the data of the node at the given index.
    // 
    // @param index the index of the node
    // @param value the new data to be stored in the node
    bool setNode(int index, T value)
    {
        Node<T>* temp = getNode(index);
        if (temp == nullptr) return false;
        temp->data = value;
        return true;
    }

    // Inserts a new node with the given data at the given index.
    // 
    // @param index the index at which the new node will be inserted
    // @param value the data to be stored in the new node
    bool insertNode(int index, T value)
    {
        if (index < 0 || index > length) return false;
        if (index == 0) {
            addFront(value);
            return true;
        }
        if (index == length) {
            addBack(value);
            return true;
        }

        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = getNode(index);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        length++;
        return true;
    }

    // Removes the node at the given index.
    // 
    // @param index the index of the node to be removed
    bool deleteNode(int index)
    {
        if (index < 0 || index >= length) return false;
        if (index == 0) {
            removeFront();
            return true;
        }
        if (index == length - 1) {
            removeBack();
            return true;
        }
        Node<T> *temp = getNode(index);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
        return true;
    }

    // Reverse the list.
    void reverse()
    {
        Node<T> *temp = head;
        head = tail;
        tail = temp;
        while(nullptr != temp)
        {
            Node<T> *next = temp->next;
            temp->next = temp->prev;
            temp->prev = next;
            temp = next;
        }
    }
    
};


int main()
{
    DoublyLinkedList<int> list;
    list.addFront(1);
    list.addFront(2);
    list.addFront(3);
    list.addBack(4);
    list.addBack(5);
    list.printList();

    list.reverse();
    list.printList();

    list.removeFront();
    list.removeBack();
    list.printList();

    list.setNode(1, 6);
    list.setNode(3, 7);
    list.printList();

    list.insertNode(3, 8);
    list.printList();

    list.deleteNode(3);
    list.printList();

    list.reverse();
    list.printList();

    cout << list.getLength() << endl;

    return 0;
}