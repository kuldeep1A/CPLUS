#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:;
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;

            high--;
            low++;
        }

        return nums[k - 1];
    }
};

int main()
{
    vector<int> num1{3, 2, 1, 5, 6, 4};
    int k1 = 2;
    Solution my;
    cout << "first " << my.findKthLargest(num1, k1) << endl;

    vector<int> num2{3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "first " << my.findKthLargest(num2, k2) << endl;
}