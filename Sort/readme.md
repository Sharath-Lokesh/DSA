### Sort Class Methods (C++)
This class provides various sorting algorithms for integer arrays.

### Methods:
- `merge(int arr[], int l, int m, int r)`: Merges two sorted sub-arrays arr[l...m] and arr[m+1...r] into a single sorted sub-array arr[l...r]. (Used by Merge Sort)
- `swap(int arr[], int i, int j)`: Swaps the elements at indices i and j in the array.
- `pivot_index(int array[], int pivotIndex, int endIndex)`: Chooses a pivot element and partitions the array around it, placing elements less than the pivot to its left and elements greater than or equal to the pivot to its right. Returns the final index of the pivot element. (Used by Quick Sort)
- `BubbleSort(int arr[], int n)`: Sorts the array in place using Bubble Sort.
- `SelectionSort(int arr[], int n)`: Sorts the array in place using Selection Sort.
- `InsertionSort(int arr[], int n)`: Sorts the array in place using Insertion Sort.
- `MergeSort(int arr[], int l, int r)`: Sorts the sub-array arr[l...r] in place using the Merge Sort algorithm.
- `QuickSort(int arr[], int l, int r)`: Sorts the sub-array arr[l...r] in place using the Quick Sort algorithm.
- `printArray(int arr[], int size)`: Prints the contents of the array to the console.
