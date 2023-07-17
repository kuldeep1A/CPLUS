#include <iostream>
using namespace std;

// Write a program to sort binary array in linear time.
void sortBinaryArray(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    int i = 0;

    while (i <= high)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[low]);
            low++;
            i++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[high]);
            high--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements in the binary array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the binary array (0s and 1s only):" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sortBinaryArray(arr, n);

    cout << "Sorted binary array:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}