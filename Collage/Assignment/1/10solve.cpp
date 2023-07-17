#include <iostream>
#include <unordered_set>
using namespace std;

// Write a program find sub-array with 0 sum.
bool Subarray(int arr[], int n)
{
    unordered_set<int> prefixSums;
    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];

        if (sum == 0 || prefixSums.find(sum) != prefixSums.end())
        {
            return true;
        }

        prefixSums.insert(sum);
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    if (Subarray(arr, n))
    {
        cout << "The array contains a sub-array with zero sum." << endl;
    }
    else
    {
        cout << "The array does not contain any sub-array with zero sum." << endl;
    }

    return 0;
}