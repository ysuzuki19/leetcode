class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return 1;
    sort(nums.begin(), nums.end());
    int longest = 0;
    int sublen = 1;
    for (int i=1; i<nums.size(); ++i) {
      if (nums[i] == nums[i-1]) continue;
      if (nums[i]-nums[i-1]==1) {
        sublen++;
      } else {
        longest = max(longest, sublen);
        sublen = 1;
      }
    }
    return max(longest, sublen);
  }
};