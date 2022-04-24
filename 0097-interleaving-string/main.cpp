class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) {
      return false;
    }
    vector<vector<bool>> dp(s1.length()+1, vector<bool>(s2.length()+1, false));
    for (int i=0; i<dp.size(); ++i) {
      for (int j=0; j<dp[i].size(); ++j) {
        if (i==0 && j==0) {
          dp[i][j] = true;
        } else {
          char c3 = s3[i + j - 1];
          if (i==0) {
            dp[i][j] = (dp[i][j-1] && s2[j-1] == c3);
          } else if (j==0) {
            dp[i][j] = (dp[i-1][j] && s1[i-1] == c3);
          } else {
            dp[i][j] = (dp[i-1][j] && s1[i-1]==c3) || (dp[i][j-1] && s2[j-1]==c3);
          }
        }
      }
    }
    return dp[s1.length()][s2.length()];
  }
};