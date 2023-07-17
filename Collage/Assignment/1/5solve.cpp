#include <iostream>
using namespace std;

// Write a program to read n number of values in an array and display them in reverse order.
int main()
{
    int size;
    cout << "Enter the number of values: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " values:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Values in reverse order: " << endl;
    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}