//
// Author: Sharath Lokesh
//

#include<iostream>
#include <algorithm>

using namespace std;

class Sort
{
    // Merge two sorted arrays
    void merge(int arr[], int l, int m, int r)
    {
        int l_size = m - l + 1; // l_size = 5 - 0 + 1 = 6
        int r_size = r - m; // r_size = 9 - 5 = 4
        int l_arr[l_size], r_arr[r_size]; //Creating two arrays of size l_size and r_size

        for (int i = 0; i < l_size; ++i)
            l_arr[i] = arr[l + i]; // l_arr = [0, 1, 2, 3, 4, 5]
        for (int j = 0; j < r_size; ++j)
            r_arr[j] = arr[m + 1 + j]; // r_arr = [6, 7, 8, 9]
        
        int i = 0;
        int j = 0;
        int k = l; // k = 0

        // Merge two sorted arrays into one
        while (i < l_size && j < r_size)
        {
            if (l_arr[i] <= r_arr[j])
            {
                arr[k] = l_arr[i];
                ++i;
            }
            else
            {
                arr[k] = r_arr[j];
                ++j;
            }
            ++k;
        }
        // Copy remaining elements of l_arr[] if any
        while (i < l_size)
        {
            arr[k] = l_arr[i];
            ++i;
            ++k;
        }

        // Copy remaining elements of r_arr[] if any
        while (j < r_size)
        {
            arr[k] = r_arr[j];
            ++j;
            ++k;
        }
    }

    // Function to swap two elements
    void swap(int arr[], int i, int j)
    { 
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // 
    int pivot_index(int array[], int pivotIndex, int endIndex)
    {
        int swapIndex = pivotIndex;
        for (int i = pivotIndex + 1; i <= endIndex; ++i)
        {
            if (array[i] < array[pivotIndex])
            {
                swapIndex++;
                swap(array, swapIndex, i);
            }
        }
        swap(array, pivotIndex, swapIndex);

        return swapIndex;
    }
    public:

        // Function to sort an array using Bubble Sort
        void BubbleSort(int arr[], int n)
        {
            int i, j;
            // int n = sizeof(arr) / sizeof(arr[0]);
            for(i = 0; i < n - 1; ++i)
            {
                for (j = 0; j < n - i - 1; ++j)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        swap(arr, j, j + 1);
                    }
                }
            }
        }

        // Function to sort an array using Selection Sort
        void SelectionSort(int arr[], int n)
        {
            int i, j, min_idx;
            for (i = 0; i < n - 1; ++i)
            {
                min_idx = i;
                for (j = i + 1; j < n; ++j)
                    if (arr[j] < arr[min_idx])
                        min_idx = j;

                if(i==min_idx) continue;

                swap(arr, i, min_idx);
            }
        }
        
        // Function to sort an array using Insertion Sort
        void InsertionSort(int arr[], int n)
        {
            int i, key, j;
            for (i = 1; i < n; ++i)
            {
                key = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    --j;
                }
                arr[j+1] = key;
            }
        }

        //merge sort
        void MergeSort(int arr[], int l, int r)
        {
            if (l < r)
            {
                int m = l + (r - l) / 2;
                MergeSort(arr, l, m);
                MergeSort(arr, m + 1, r);
                merge(arr, l, m, r);
            }
            else return;
        }

        // quick sort
        void QuickSort(int arr[], int l, int r)
        {
            if (l < r)
            {
                int pi = pivot_index(arr, l, r);
                QuickSort(arr, l, pi - 1);
                QuickSort(arr, pi + 1, r);
            }
            else return;
        }

        // Utility function to print an array
        void printArray(int arr[], int size)
        {
            int i;
            cout << "[ ";
            for (i = 0; i < size; ++i)
                cout << arr[i] << " ";
            cout << "]" <<endl;
        }
};

int main()
{
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    
    Sort ob;
    cout << "Shuffled array: ";
    ob.printArray(arr, n);



    ob.BubbleSort(arr, n);
    cout << "Bubble Sort array: ";
    ob.printArray(arr, n);

    cout << "Shuffled array: ";
    random_shuffle(begin(arr), end(arr));
    ob.printArray(arr, n);

    ob.SelectionSort(arr, n);
    cout << "Selection Sort array: ";
    ob.printArray(arr, n);

    cout << "Shuffled array: ";
    random_shuffle(begin(arr), end(arr));
    ob.printArray(arr, n);

    ob.InsertionSort(arr, n);
    cout << "Insertion Sort array: ";
    ob.printArray(arr, n);

    cout << "Shuffled array: ";
    random_shuffle(begin(arr), end(arr));
    ob.printArray(arr, n);


    ob.MergeSort(arr, 0, n - 1);
    cout << "Merge Sort array: ";
    ob.printArray(arr, n);

    cout << "Shuffled array: ";
    random_shuffle(begin(arr), end(arr));
    ob.printArray(arr, n);


    ob.QuickSort(arr, 0, n - 1);
    cout << "Quick Sort array: ";
    ob.printArray(arr, n);

    return 0;
}
