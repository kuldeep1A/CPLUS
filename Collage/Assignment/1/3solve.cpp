#include <iostream>
using namespace std;

void deleteElement(int arr[], int size, int element)
{
    int foundIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1)
    {
        // Shift the elements after the deleted element to the left
        for (int i = foundIndex; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element " << element << " deleted from the array." << endl;

        cout << "UpDate Array: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Element " << element << " not found in the array." << endl;
    }
}

int main()
{
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int size = 10;
    int element;

    std::cout << "Enter the element to delete: ";
    std::cin >> element;

    deleteElement(arr, size, element);

    return 0;
}
