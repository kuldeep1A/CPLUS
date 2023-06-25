#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool hasPairWithSum(const vector<int> &arr, int target)
    {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right)
        {
            int summ = arr[left] + arr[right];
            if (summ == target)
            {
                return true;
            }
            else if (summ < target)
            {
                left += 1;
            }
            else
            {
                right -= 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 9};
    int target = 10;

    Solution myObj;

    bool res = myObj.hasPairWithSum(arr, target);
    cout << (res ? "true" : "false") << endl;
}