#include <iostream>
using namespace std;

// Write a program to implement one dimensional array and find the sum of array elements.
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = 0;
    for (int num : array)
    {
        sum += num;
    }
    cout << sum << " ";
}