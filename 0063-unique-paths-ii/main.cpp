class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.front().front()) return 0;
    if (obstacleGrid.back().back()) return 0;
    for (auto &row: obstacleGrid) {
      for (auto &cell: row) {
        if (cell) cell = -1;
      }
    }
    obstacleGrid[0][0] = 1;
    for (int i=0; i<obstacleGrid.size(); ++i) {
      for (int j=0; j<obstacleGrid[i].size(); ++j) {
        if (obstacleGrid[i][j] != -1) {
          if (i+1 != obstacleGrid.size() && obstacleGrid[i+1][j] != -1) {
            obstacleGrid[i+1][j] += obstacleGrid[i][j];
          }
          if (j+1 != obstacleGrid[i].size() && obstacleGrid[i][j+1] != -1) {
            obstacleGrid[i][j+1] += obstacleGrid[i][j];
          }
        }
      }
    }
    if (obstacleGrid.back().back() == -1) return 0;
    return obstacleGrid.back().back();
  }
};