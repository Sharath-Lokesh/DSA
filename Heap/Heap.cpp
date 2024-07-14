#include <iostream>
#include <vector>
#include <climits>


using namespace std;

class minHeap
{
    protected:
    vector<int> heap;    
    // returns the index of the left child
    int leftIdx(int i) { return 2 * i + 1; }
    // returns the index of the right child
    int rightIdx(int i) { return 2 * i + 2; }
    // returns the index of the parent
    int parentIdx(int i) { return (i - 1) / 2; }

    // swapes two elements
    void swap(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    // sink down the heap
    void sinkDown(int i)
    {
        int minIdx = i;
        while (true)
        {
            int left = leftIdx(i);
            int right = rightIdx(i);
            if (left < heap.size() && heap[left] < heap[minIdx])
                minIdx = left;
            if (right < heap.size() && heap[right] < heap[minIdx])
                minIdx = right;
            if (minIdx == i)
                break;
            swap(i, minIdx);
            i = minIdx;
        }
        
    }

    public:

    // display the heap
    void display()
    {
        cout << "[";
        for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i];
            if (i != heap.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    // get the heap vector
    const vector<int>& getHeap() const { return heap; }

    // insert an element
    void insert(int val)
    {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i != 0 && heap[parentIdx(i)] > heap[i])
        {
            swap(i, parentIdx(i));
            i = parentIdx(i);
        }
    }

    // remove an element
    int remove()
    {
        if (heap.size() == 0)
            return INT_MIN;

        int minVal = heap.front();
        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }

        return minVal;
    }
};


class maxHeap: public minHeap
{
    // vector<int> heap;
    void sinkDown(int i)
    {
        int maxIdx = i;
        while (true)
        {
            int left = leftIdx(i);
            int right = rightIdx(i);
            if (left < heap.size() && heap[left] > heap[maxIdx])
                maxIdx = left;
            if (right < heap.size() && heap[right] > heap[maxIdx])
                maxIdx = right;
            if (maxIdx == i)
                break;
            swap(i, maxIdx);
            i = maxIdx;
        }
    }
    public:

    // insert an element in the heap
    void insert(int val)
    {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i != 0 && heap[parentIdx(i)] < heap[i])
        {
            swap(i, parentIdx(i));
            i = parentIdx(i);
        }
    }

    //  remove an element from the heap
    int remove()
    {
        if (heap.size() == 0)
            return INT_MAX;

        int maxVal = heap.front();
        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }

        return maxVal;
    }


};
int main()
{
    minHeap h;
    h.insert(5);
    h.insert(3);
    h.insert(7);
    h.insert(2);
    h.insert(4);
    h.insert(6);
    h.insert(8);
    h.display();
    cout << h.remove() << endl;
    h.display();

    cout << h.remove() << endl;
    h.display();

    cout << h.remove() << endl;
    h.display();

    cout << h.remove() << endl;
    h.display();

    cout << "\n\n\n";
    maxHeap mh;
    mh.insert(5);
    mh.insert(3);
    mh.insert(7);
    mh.insert(2);
    mh.insert(4);
    mh.insert(6);
    mh.insert(8);
    mh.display();
    cout << mh.remove() << endl;
    mh.display();

    cout << mh.remove() << endl;
    mh.display();

    cout << mh.remove() << endl;
    mh.display();

    cout << mh.remove() << endl;
    mh.display();

    return 0;
}