//
// Author: Sharath Lokesh
//

#include <limits>
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

template <typename T, typename U>
class Node {
    public:
        T key;
        U value;
        Node<T, U>* next;

        // Constructor for Node
        Node(T key, U value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

template <typename T, typename U>
class HashTable {
    private:
        static const int SIZE = 17;
        Node<T, U>* dataMap[SIZE];

        // Hash Function
        int hashFunc(T key) {
            int hash = 0;
            if constexpr (std::is_same_v<T, string>)
            {
                for (int i = 0; i < key.length(); i++) {
                    int asciiValue = int(key[i]);
                    hash = (hash + asciiValue *  31) % SIZE;
                }
            }
            else //if constexpr (std::is_same_v<T, char>)
            {
                int asciiValue = int(key);
                hash = (hash + asciiValue *  31) % SIZE;
            }
            
            return hash;
        }

    public:

        // Destructor
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node<T, U>* head = dataMap[i];
                Node<T, U>* temp = head;
                while (nullptr != head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }
        
        // Print Table
        void printTable() {
            cout << "--------------- Hash Table ---------------" << endl;
            for(int i = 0; i < SIZE; i++) {
                cout << i << ":" << endl;
                if(dataMap[i]) {
                    Node<T, U>* temp = dataMap[i];
                    while (nullptr != temp) {
                        cout << "   {" << temp->key << ": " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }
        
        // Set Function: handles duplicates
        void set(T key, U value) {
            int index = hashFunc(key);
            Node<T, U>* newNode = new Node<T, U>(key, value);
            if (nullptr == dataMap[index]) 
            {
                dataMap[index] = newNode;
            } 
            else 
            {
                Node<T, U>* temp = dataMap[index];
                while (nullptr != temp->next) 
                {
                    if (temp->key == key) 
                    {
                        temp->value = value;
                        return;
                    }
                    temp = temp->next;
                }
                if (temp->key == key) 
                {
                    temp->value = value;
                    return;
                }
                temp->next = newNode;
            }
        }
    
        // Get Function
        int get(T key) {
            int index = hashFunc(key);
            Node<T, U>* temp = dataMap[index];
            while (nullptr != temp) {
                if (temp->key == key) return temp->value;
                temp = temp->next;
            }
            return std::numeric_limits<U>::min();
        }

        // Get the Keys Function
        vector<T> keys() {
            vector<T> allKeys;
            for(int i = 0; i < SIZE; i++) {
                Node<T, U>* temp = dataMap[i];
                while (nullptr != temp) {
                    allKeys.push_back(temp->key);
                    temp = temp->next;
                }
            }
            return allKeys;
        }   

};


int main() {
    cout<< "---------------- string keys ----------------" << endl;
    HashTable<string, int>* myHashTable = new HashTable<string, int>();

    myHashTable->set("one", 1);
    myHashTable->set("two", 2);
    myHashTable->set("three", 3);
    myHashTable->set("four", 4);

    cout << "one: " << myHashTable->get("one") << endl;
    cout << "four: " << myHashTable->get("four") << endl;
    cout<<"five:" << myHashTable->get("five") << endl;

    myHashTable->printTable();
    
    vector<string> myKeys = myHashTable->keys();

    for (auto key : myKeys) {  
        cout << key << " ";
    }

    cout<<endl;

    cout<< "---------------- int keys ----------------" << endl;
    HashTable<int, int>* myHashTable1 = new HashTable<int, int>();

    myHashTable1->set(1, 1);
    myHashTable1->set(2, 2);
    myHashTable1->set(3, 3);
    myHashTable1->set(4, 4);

    myHashTable1->printTable();

    cout<< "---------------- char keys ----------------" << endl;
    HashTable<char, int>* myHashTable2 = new HashTable<char, int>();

    myHashTable2->set('a', 1);
    myHashTable2->set('b', 2);
    myHashTable2->set('c', 3);
    myHashTable2->set('d', 4);
    myHashTable2->set('A', 5);
    myHashTable2->set('a', 6);

    myHashTable2->printTable();

    return 0;
}