Doubly Linked List supports the following methods:

**Constructors**:
- `DoublyLinkedList()`: Constructs an empty doubly linked list.
- `DoublyLinkedList(T value)`: Constructs a doubly linked list with a single node containing the given value.

**Destructor**:
- `~DoublyLinkedList()`: Destructor that deallocates all nodes in the list.

**Getter methods**:
- `int getLength() const`: Returns the length of the list (number of nodes).
- `Node<T>* getHead() const`: Returns the head node of the list.
- `Node<T>* getTail() const`: Returns the tail node of the list.

**Manipulation methods**:
- `void addBack(T value)`: Adds a new node with the given data to the back of the list.
- `void addFront(T value)`: Adds a new node with the given data to the front of the list.
- `void removeFront()`: Removes the node at the front of the list.
- `void removeBack()`: Removes the node at the back of the list.
- `Node<T>* getNode(int index)`: Returns the node at the given index (zero-based indexing).
- `bool setNode(int index, T value)`: Sets the data of the node at the given index.
- `bool insertNode(int index, T value)`: Inserts a new node with the given data at the specified index.
- `bool deleteNode(int index)`: Removes the node at the given index.
- `void reverse()`: Reverses the order of nodes in the list.

**Other methods**:
- `void printList()`: Prints the data of all nodes in the list to the console.
