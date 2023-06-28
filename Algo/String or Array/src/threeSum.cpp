#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        if (nums.size() < 3)
        {
            return {};
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l - 1])
                    {
                        ++l;
                    }
                    while (l < r && nums[r] == nums[r + 1])
                    {
                        --r;
                    }
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    Solution myObj;
    vector<vector<int>> res = myObj.threeSum(nums);

    for (vector<int> triplate : res)
    {
        cout << ".>";
        for (int num : triplate)
        {
            cout << num << " ";
        }
    }
}