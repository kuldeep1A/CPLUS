#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (int num: nums){
            minHeap.push(num);
            if (minHeap.size() > k){
                minHeap.pop();
            }
        }

        return minHeap.top();
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