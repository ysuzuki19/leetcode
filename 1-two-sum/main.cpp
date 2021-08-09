class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> lut;
    for (int i=0; i<nums.size(); ++i) {
      auto found = lut.find(target - nums[i]);
      if (found != lut.end()) {
        return {i, found->second};
      }
      lut[nums[i]] = i;
    }
    return {-1,-1};
  }
};