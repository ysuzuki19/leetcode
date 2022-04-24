class Solution {
public:
  int partitionDisjoint(vector<int>& nums) {
    vector<int> minis(nums.size());
    minis.back() = nums.back();
    for (int i=nums.size()-2; i!=-1; --i) {
      minis[i] = min(minis[i+1], nums[i]);
    }
    int maximum = 0;
    for (int i=0; i<nums.size()-1; ++i) {
      if (nums[i] <= minis[i+1] && maximum <= minis[i+1]) return i + 1;
      maximum = max(maximum, nums[i]);
    }
    return nums.size()-1;
  }
};