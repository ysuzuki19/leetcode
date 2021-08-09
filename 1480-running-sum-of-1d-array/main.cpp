class Solution {
public:
  vector<int> runningSum(vector<int>& nums) {
    vector<int> sums;
    sums.reserve(nums.size());
    sums.push_back(nums.front());
    for (int i=1; i<nums.size(); ++i) {
      sums.push_back(sums[i-1] + nums[i]);
    }
    return sums;
  }
};