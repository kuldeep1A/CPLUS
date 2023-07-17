#include <iostream>
#include <limits>
using namespace std;

// Write a program to implement one dimensional array and find the max and min number from
// array elements.
int main()
{
    int array[] = {3, 4, 5, 6, 7, 8, 1, 2, 9};
    int max = numeric_limits<int>::min();
    int min = numeric_limits<int>::max();
    for (int num : array)
    {
        if (num < min)
        {
            min = num;
        }
        if (num > max)
        {
            max = num;
        }
    }
    cout << "min: " << min << " " << endl
         << "max: " << max;
}