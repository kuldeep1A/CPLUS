#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> hasDuplicated;
        for (int num : nums)
        {
            if (hasDuplicated.count(num))
            {
                return true;
                        }
            hasDuplicated.insert(num);
        }
        return false;
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6};
    Solution my;
    bool res = my.containsDuplicate(nums);
    cout << (res ? "true" : "false");
}