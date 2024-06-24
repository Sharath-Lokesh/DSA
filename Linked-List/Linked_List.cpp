/**
* Author: Sharath Lokesh
*/
#include <iostream>

using namespace std;

template<typename T1>
class Node
{
public:
    T1 data;
    Node<T1> *next;
    /**
    * Constructs a new Node object with the given data.
    *
    * @param d the data to be stored in the Node
    */
    Node(T1 d)
    {
        data = d;
        next = nullptr;
    }
};
template<typename T>
class LinkedList
{
    Node<T> *head;
    Node<T> *tail;
    int length;

    

public:
    LinkedList(): length(0), head(nullptr), tail(nullptr) {}
    LinkedList(T value): length(1), head(new Node<T>(value)), tail(head) {}

    ~LinkedList()
    {
        Node<T> *temp = head;
        while (nullptr != head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    /**
    * A function to print the elements of the linked list.
    *
    * @return void
    */
    void printList()
    {
        Node<T> *temp = head;
        cout << "[";
        while (nullptr != temp)
        {
            cout << temp->data;
            if (nullptr != temp->next)
                cout << ", ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    /**
    * Retrieves the head node of the linked list.
    *
    * @return A pointer to the head node of the linked list.
    */
    Node<T>* getHead () const
    {
        return head;
    }

    /**
    * @brief Get the Tail object
    * 
    * @return Node<T>* 
    */
    Node<T>* getTail () const
    {
        return tail;
    }

    /**
    * @brief Get the Length object
    * 
    * @return int 
    */
    int getLength () const
    {
        return length;  
    }

    /**
    * @brief Add a new node at the end of the linked list
    * 
    * @param value 
    * @return void
    */
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
            tail = newNode;
        }
        length++;
    }

    /**
    * @brief Add a new node at the front of the linked list
    * 
    * @param value 
    * @return void
    */
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
            head = newNode;
        }
        length++;
    }

    /**
    * @brief Remove the node at the front of the linked list
    * 
    * @return void
    */
    void removeFront()
    {
        if (nullptr == head)
            return;

        Node<T> *temp = head;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
            head = head->next;
        delete temp;
        length--;
    }

    /**
    * @brief Remove the node at the end of the linked list
    * 
    * @return void
    */
    void removeBack()
    {
        if (nullptr == head)
            return;

        Node<T> *temp = head;
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            while (temp->next != tail)
                temp = temp->next;
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        length--;
    }

    /**
    * @brief Set the Node object
    * 
    * @param index 
    * @param value 
    * @return true 
    * @return false 
    */
    bool setNode(int index, T value)
    {
        if (index < 0 || index >= length) return false;
        Node<T> *temp = head;
        for (int i = 0; i < index; ++i)
            temp = temp->next;
        temp->data = value;
        return true;
    }
    
    /**
    * @brief Get the Node object
    * 
    * @param index 
    * @return Node<T>* 
    */
    Node<T>* getNode(int index)
    {
        if (index < 0 || index >= length) return nullptr;
        Node<T> *temp = head;
        for (int i = 0; i < index; ++i)
            temp = temp->next;
        return temp;
    }

    /**
    * @brief Insert a new node at the given index
    * 
    * @param index 
    * @param value 
    * @return true 
    * @return false 
    */
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
        Node<T> *temp = head;
        for (int i = 0; i < index - 1; ++i)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    /**
    * @brief Delete the node at the given index
    * 
    * @param index 
    * @return true 
    * @return false 
    */
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
        Node<T> *temp = head;
        for (int i = 0; i < index - 1; ++i)
            temp = temp->next;
        Node<T> *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        length--;
        return true;
    }

    /**
    * @brief Reverse the linked list
    * 
    * @return void
    */
    void reverse()
    {
        Node<T> *current = head;
        head = tail;
        tail = current;
        Node<T> *prev = nullptr;
        Node<T> *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    }

    /**
    * @brief Clear the linked list
    * 
    * @return void
    */
    void clearList()
    {
        while (length > 0)
            removeFront();
    }
};

int main()
{

    LinkedList<int> myLinkedList(1);
    
    myLinkedList.addBack(2);
    myLinkedList.addFront(3);
    myLinkedList.addBack(0);
    myLinkedList.addFront(4);

    myLinkedList.printList();
    
    myLinkedList.removeFront();
    myLinkedList.removeBack();

    myLinkedList.printList();

    myLinkedList.setNode(1, 5);
    myLinkedList.setNode(3, 6);
    myLinkedList.printList();

    cout<<"Value at index 2: "<<(myLinkedList.getNode(2))->data<<endl;

    myLinkedList.reverse();
    myLinkedList.printList();

    cout << myLinkedList.getLength() << endl;

    LinkedList<string> myLinkedList2;
    myLinkedList2.addBack("Hello");
    myLinkedList2.addFront("World");

    myLinkedList2.printList();
    myLinkedList2.insertNode(1, "Again");
    myLinkedList2.printList();

    myLinkedList2.deleteNode(1);
    myLinkedList2.printList();
    cout << (myLinkedList2.getNode(1))->data << endl;

    myLinkedList2.clearList();
    myLinkedList2.printList();

    cout << "Done" << endl;
    return 0;
}