#include <iostream>
#include <limits>
using namespace std;

// Write a program to find the second smallest element in an array.

int secondSmallest(int arr[], int size)
{
    int minimum = numeric_limits<int>::max();
    int secondMinimum = numeric_limits<int>::max();
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < minimum)
        {
            secondMinimum = minimum;
            minimum = arr[i];
        }
        else if (arr[i] < secondMinimum && arr[i] != minimum)
        {
            secondMinimum = arr[i];
        }
    }
    return secondMinimum;
}
int main()
{
    int array[] = {3, 4, -1, -2, 5, 6, 7, 8, 9};
    int size = 9;

    int res = secondSmallest(array, 9);

    if (res != numeric_limits<int>::max())
    {
        cout << "The second smallest element in the array is: " << res << endl;
    }
    else
    {
        cout << "There is no second smallest element in the array." << endl;
    }
}