MyQueue class contains the following methods:

**Constructors**:
- `MyQueue()`: Constructs an empty queue.
- `MyQueue(T value) (optional)`: Constructs a queue with a single node containing the given value (constructor commented out in the provided code).

**Destructor**:
- `~MyQueue()`: Destructor that deallocates all nodes in the queue.

**Getter methods**:
- `Node<T>* getHead() const`: Returns the head node of the queue (may be nullptr for an empty queue).
- `Node<T>* getTail() const`: Returns the tail node of the queue (may be nullptr for an empty queue).
- `int getLength() const`: Returns the length of the queue (number of nodes).

**Manipulation methods**:
- `void addElement(T value)`: Adds a new element (of type T) to the back of the queue.
- `T removeElement()`: Removes and returns the element at the front of the queue. If the queue is empty, returns std::numeric_limits<T>::min() (minimum value for the data type).

**Other methods**:
- `void printQueue()`: Prints the data of all elements in the queue to the console (in order from front to back).
void printQueue(): Prints the data of all elements in the queue to the console (in order from front to back).
