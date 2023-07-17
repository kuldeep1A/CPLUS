#include <iostream>
using namespace std;

// Write a program to copy the elements of one array into another array.
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int another[9];
    for (int i = 0; i < 9; i++)
    {
        another[i] = array[i];
    }

    for (int num : another)
    {
        cout << num << " ";
    }
}