class Solution {
public:
  int minMoves2(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
    return accumulate(nums.begin(), nums.end(), 0, [&nums](int acc, int i) {
      return acc + abs(nums[nums.size()/2] - i);
    });
  }
};