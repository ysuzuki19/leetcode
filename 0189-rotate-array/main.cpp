class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    vector<int> rotated;
    rotated.reserve(nums.size());
    for (int i=nums.size()-k; i<nums.size(); ++i) {
      rotated.push_back(nums[i]);
    }
    for (int i=0; i<nums.size()-k; ++i) {
      rotated.push_back(nums[i]);
    }
    nums = rotated;
  }
};