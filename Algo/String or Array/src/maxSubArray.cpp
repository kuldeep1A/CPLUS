#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = -589875;
        int currentSum = 0;

        for (int num : nums)
        {
            currentSum += num;
            if (maxSum < currentSum)
            {
                maxSum = currentSum;
            }

            if (currentSum < 0)
            {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution me;

    int res = me.maxSubArray(nums);
    cout << res;
}