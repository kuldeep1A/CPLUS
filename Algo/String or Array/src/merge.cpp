#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (const vector<int> interval : intervals)
        {
            if (ans.empty() || ans.back()[1] < interval[0])
            {
                ans.push_back(interval);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    Solution m;
    vector<vector<int>> res = m.merge(intervals);
    for (vector<int> interval : res)
    {
        cout << "-> ";
        for (int ele : interval)
        {
            cout << ele << " ";
        }
    }
}