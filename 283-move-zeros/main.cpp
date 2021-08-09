class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    stable_sort(nums.begin(),nums.end(), [](int a, int b){ return b==0; });
  }
};