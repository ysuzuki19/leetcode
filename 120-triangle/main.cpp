class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    for (size_t i=triangle.size()-2; i<triangle.size(); --i) {
      for (int j=0; j<triangle[i].size(); ++j) {
        triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
      }
    }
    return triangle[0][0];
  }
};