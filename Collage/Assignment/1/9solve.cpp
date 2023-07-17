#include <iostream>
#include <unordered_set>

bool findPairWithSum(int arr[], int size, int targetSum, int &num1, int &num2)
{
    std::unordered_set<int> complements;

    for (int i = 0; i < size; i++)
    {
        int complement = targetSum - arr[i];

        if (complements.find(complement) != complements.end())
        {
            num1 = complement;
            num2 = arr[i];
            return true;
        }

        complements.insert(arr[i]);
    }

    return false;
}

int main()
{
    int arr[] = {2, 4, 7, 11, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 13;
    int num1, num2;

    if (findPairWithSum(arr, size, targetSum, num1, num2))
    {
        std::cout << "Pair found: " << num1 << " and " << num2 << std::endl;
    }
    else
    {
        std::cout << "No pair found with the given sum." << std::endl;
    }

    return 0;
}
;