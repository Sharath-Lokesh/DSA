### minHeap Class
The minHeap class provides the core functionalities for a min-heap:

**Protected Members**:
- `heap`: An internal vector (list) to store the heap elements.
- `Helper functions`: for calculating child and parent indices within the heap structure.
- `swap`: function to exchange elements at two indices.
- `sinkDown`: function to maintain the min-heap property by swapping elements down the heap if needed.

**Public Members**:
- `display`: Prints the contents of the heap to the console.
- `getHeap`: Provides a read-only access to the internal heap vector.
- `insert`: Inserts a new element into the heap, maintaining the min-heap property (smallest element at the root).
- `remove`: Removes and returns the minimum element from the heap.

### maxHeap Class
The maxHeap class inherits from minHeap and overrides the sinkDown, remove and insert methods to create a max-heap:

**Overrides**:
- `sinkDown`: Swaps elements upwards if the child is greater than the parent, maintaining the max-heap property (largest element at the root).
- `insert`: Swaps elements upwards if the child is less than the parent, maintaining the max-heap property.
- `remove`: Removes and returns the maximum element from the heap
