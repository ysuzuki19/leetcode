class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    int maximum = 1;
    vector<pair<int,int>> dp(nums.size(), make_pair(1,1));
    for (int i=1; i<nums.size(); ++i) {
      for (int j=i-1; j!=-1; --j) {
        if (nums[i] == nums[j]) continue;

        if (nums[i] > nums[j]) {
          if (dp[i].first < dp[j].second + 1) {
            dp[i].first = dp[j].second + 1;
          }
        } else {
          if (dp[i].second < dp[j].first + 1) {
            dp[i].second = dp[j].first + 1;
          }
        }
      }
      maximum = max(maximum, max(dp[i].first, dp[i].second));
    }
    return maximum;
  }
};