#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numToIndex;
        int n = nums.size();

        for (int i = 0; i < nums.size(); ++i)
        {
            if (const auto it = numToIndex.find(target - nums[i]); it != numToIndex.cend())
                return {it->second, i};
            numToIndex[nums[i]] = i;
        }
        throw;
    }
};

int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 17;

    Solution myObj;

    vector<int> res = myObj.twoSum(nums, target);

    for (int ele : res)
    {
        cout << ele << " ";
    }
}