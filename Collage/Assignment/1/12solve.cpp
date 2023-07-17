#include <iostream>
#include <vector>
using namespace std;

// Write a program to find a duplicate element in a limited range array.
int findDuplicate(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> count(n, 0);

    for (int num : arr)
    {
        count[num]++;
        if (count[num] > 1)
        {
            return num;
        }
    }

    return -1;
}

int main()
{

    vector<int> arr{1, 2, 3, 4, 5, 5};

    int duplicate = findDuplicate(arr);

    if (duplicate != -1)
    {
        cout << "The duplicate element in the array is: " << duplicate << endl;
    }
    else
    {
        cout << "No duplicate element found in the array." << endl;
    }

    return 0;
}