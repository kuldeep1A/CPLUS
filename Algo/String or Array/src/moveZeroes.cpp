#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int i = 0;
    for(const int num: nums){
        if (num != 0){
            nums[i++] = num;
        }
    }
    while(i < nums.size()){
        nums[i++] = 0;
    }
    for(const int num: nums){
        cout << num << " ";
    }
  }
};

int main() {
    vector<int> nums;
    int i = 0;
    for(i; i < 3; i++){
        nums.push_back(0);
    }
    for(i; i < 10; i++){
        nums.push_back(i);
    }
    for(const int num: nums){
        cout << num << " ";
    }
    cout << endl;
    Solution solve;
    solve.moveZeroes(nums);
}