This code implements a basic hash table class in C++ with template support for key and value types.

**Class Definition**:
- `Node<T, U>`: Represents a node in the hash table linked list, storing a key, value, and a pointer to the next node.
- `HashTable<T, U>`: The main hash table class with template parameters for key and value types.

**Methods**:
- `Destructor`: Deallocates memory for all nodes in the table.
- `printTable()`: Prints the contents of the hash table, displaying key-value pairs for each bucket.
- `set(T key, U value)`: Sets a key-value pair in the hash table. Handles duplicates by updating the value if the key already exists.
- `get(T key)`: Gets the value associated with a key. Returns the minimum value for the value type if the key is not found.
- `keys()`: Returns a vector containing all the keys currently stored in the hash table.

**Hash Function**:
- `hashFunc(T key)`: Calculates the hash value for a given key. Uses a different approach for strings (multiplication by a prime and addition) and integers (simple modulus).
