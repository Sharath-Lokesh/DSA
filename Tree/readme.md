## Binary Search Tree (BST)
This class implements a basic Binary Search Tree (BST) for integer values.

#### Methods:
- `remove(Node* currentNode)`: Recursively removes nodes during tree destruction.
- `BST()`: Default constructor, initializes an empty BST.
- `~BST()`: Destructor, deallocates memory for all nodes in the tree.
- `insert(int value)`: Inserts a new node with the given value into the BST, maintaining the binary search tree property.
- `search(int value)`: Searches for a node with the given value in the BST. Returns true if found, false otherwise.

## Recursive Binary Search Tree (rBST)
This class implements a recursive Binary Search Tree (rBST) for integer values.

### Methods:
**Private**:
- `rSearch(Node* CurrentNode, int value)`: Recursively searches for a node with the given value in the BST. Returns true if found, false otherwise.
- `rInsert(Node* CurrentNode, int value)`: Recursively inserts a new node with the given value into the BST, maintaining the binary search tree property.
- `rDelete(Node* CurrentNode, int value)`: Recursively deletes a node with the given value from the BST, maintaining the binary search tree property.
- `remove(Node* currentNode)`: Recursively removes nodes during tree destruction.
- `rMin(Node* CurrentNode)`: Recursively finds the minimum value node in the right subtree.
- `rMax(Node* CurrentNode)`: Recursively finds the maximum value node in the left subtree.
**Public**:
- `rBST()`: Default constructor, initializes an empty BST.
- `~rBST()`: Destructor, deallocates memory for all nodes in the tree.
- `rInsert(int value)`: Inserts a new node with the given value into the BST.
- `rSearch(int value)`: Searches for a node with the given value in the BST. Returns true if found, false otherwise.
- `rDelete(int value)`: Deletes a node with the given value from the BST.
- `getRoot()`: Returns the root node of the BST (for advanced use cases).
- `rMin()`: Finds the minimum value stored in the BST.
- `rMax()`: Finds the maximum value stored in the BST.
