#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap
{
private:
    int size;
    int capacity;
    vector<int> items;

    int getLeftChildIndex(int parentIndex)
    {
        return 2 * parentIndex + 1;
    }

    int getRightChildIndex(int parentIndex)
    {
        return 2 * parentIndex + 2;
    }

    int getParentIndex(int childIndex)
    {
        return (childIndex - 1) / 2;
    }

    bool hasLeftChild(int index)
    {
        return getLeftChildIndex(index) < size;
    }

    bool hasRightChild(int index)
    {
        return getRightChildIndex(index) < size;
    }

    bool hasParent(int index)
    {
        return getParentIndex(index) >= 0;
    }

    int leftChild(int index)
    {
        return items[getLeftChildIndex(index)];
    }

    int rightChild(int index)
    {
        return items[getRightChildIndex(index)];
    }

    int parent(int index)
    {
        return items[getParentIndex(index)];
    }

    void swap(int indexOwn, int indexTwo)
    {
        int temp = items[indexOwn];
        items[indexOwn] = items[indexTwo];
        items[indexTwo] = temp;
    }

    void ensureExtraCapacity()
    {
        if (size == capacity)
        {
            capacity *= 2;
            items.resize(capacity);
        }
    }

    void heapifyDown()
    {
        int index = 0;
        while (hasLeftChild(index))
        {
            int samllChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && rightChild(index) < leftChild(index))
            {
                samllChildIndex = getRightChildIndex(index);
            }

            if (items[index] < items[samllChildIndex])
            {
                break;
            }
            else
            {
                swap(index, samllChildIndex);
            }
            index = samllChildIndex;
        }
    }

    void heapifyUp()
    {
        int index = size - 1;

        while (hasParent(index) && parent(index) > items[index])
        {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }

public:
    MinHeap() : capacity(10), size(0), items(capacity) {}

    int getSize()
    {
        return size;
    }

    int peek()
    {
        if (size == 0)
            throw out_of_range("Heap is empty");

        return items[0];
    }

    int poll()
    {
        if (size == 0)
            throw out_of_range("Heap is empty");

        int item = items[0];
        items[0] = items[size - 1];
        size--;
        heapifyDown();
        return item;
    }

    void add(int item)
    {
        ensureExtraCapacity();
        items[size] = item;
        size++;
        heapifyUp();
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MinHeap minHeap;
    minHeap.add(15);
    minHeap.add(20);
    minHeap.add(17);
    minHeap.add(10);
    minHeap.add(25);
    int resp = minHeap.poll();
    int res = minHeap.peek();
    cout << resp << endl;
    cout << res << endl;
    cout << minHeap.getSize() << endl;
    minHeap.printHeap();

    return 0;
}