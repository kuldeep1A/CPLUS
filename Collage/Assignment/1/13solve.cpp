#include <iostream>
#include <unordered_set>
using namespace std;

int findLargestConsecutiveSubarray(int arr[], int n)
{
    int maxLength = 0;

    unordered_set<int> numSet;

    for (int i = 0; i < n; ++i)
    {
        numSet.insert(arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        if (numSet.find(arr[i] - 1) == numSet.end())
        {
            int currentLength = 0;
            int currentNum = arr[i];

            while (numSet.find(currentNum) != numSet.end())
            {
                currentLength++;
                currentNum++;
            }

            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
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

    int largestSubarrayLength = findLargestConsecutiveSubarray(arr, n);

    cout << "The length of the largest sub-array formed by consecutive integers is: " << largestSubarrayLength << endl;

    return 0;
}