#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    bool hasPairWithSum(const vector<int> &arr, int target)
    {
        unordered_set<int> comp;

        for (int value : arr)
        {

            if (comp.find(value) != comp.end())
            {
                return true;
            }

            comp.insert(target - value);
        }
        return false;
    }
};

int main()
{
    // vector<int> arr = {1, 2, 3, 9};
    vector<int> arr = {3, 5, 9, 1, 2};
    int target = 9;

    Solution myObj;

    bool res = myObj.hasPairWithSum(arr, target);
    cout << (res ? "true" : "false") << endl;
}