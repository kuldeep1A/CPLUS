#include <iostream>
#include <vector>
using namespace std;

// Write a program to separate odd and even integers into separate arrays.
int main()
{
    const int maxSize = 9;
    int array[maxSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> odd;
    vector<int> even;

    for (int i = 0; i < maxSize; i++)
    {
        if (array[i] % 2 == 0)
        {
            even.push_back(array[i]);
        }
        else
        {
            odd.push_back(array[i]);
        }
    }

    cout << "Even array: ";
    for (int num : even)
    {
        cout << num << " ";
    }

    cout << "\nOdd array: ";
    for (int num : odd)
    {
        cout << num << " ";
    }
}