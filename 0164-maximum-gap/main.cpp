class Solution {
public:
  int maximumGap(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> diffs;
    diffs.reserve(nums.size()-1);
    for (int i=1; i<nums.size(); ++i) {
      diffs.push_back(nums[i] - nums[i-1]);
    }
    return diffs.empty()? 0: *max_element(diffs.begin(), diffs.end());
  }
};