#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Write a program to find largest sub-array formed by consecutive integers.
int findLargestConsecutiveSubarray(vector<int> arr)
{
    int maxLength = 0;
    int n = arr.size();
    unordered_set<int> numSet;

    for (int i = 0; i < n; ++i)
    {
        numSet.insert(arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        if (numSet.find(arr[i] - 1) == numSet.end())
        {
            int currLength = 0;
            int currNumber = arr[i];

            while (numSet.find(currNumber) != numSet.end())
            {
                currLength++;
                currNumber++;
            }

            maxLength = max(maxLength, currLength);
        }
    }

    return maxLength;
}

int main()
{
    vector<int> arr{1, 2, 2, 2, 3, 4, 8, 9, 10, 11, 12, 13, 14};

    int largestSubarrayLength = findLargestConsecutiveSubarray(arr);

    cout << "The length of the largest sub-array formed by consecutive integers is: " << largestSubarrayLength << endl;

    return 0;
}