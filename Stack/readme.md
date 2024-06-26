Stack class implements the following functions:

**Constructors**:
- `MyStack()`: Constructs an empty stack.
- `MyStack(T value)`: Constructs a stack with a single node containing the given value.

**Destructor**:
- `~MyStack()`: Destructor that deallocates all nodes in the stack.

**Getter methods**:
- `Node<T>* getTop() const`: Returns the top node of the stack (may be nullptr for an empty stack).
- `int getLength() const`: Returns the length of the stack (number of nodes).

**Manipulation methods**:
- `void push(T value)`: Pushes a new element (of type T) onto the stack.
- `T pop()`: Pops and removes the top element from the stack. Returns the popped value. If the stack is empty, returns std::numeric_limits<T>::min() (minimum value for the data type).

**Other methods**:
void printStack(): Prints the data of all elements in the stack to the console (in order from top to bottom).
