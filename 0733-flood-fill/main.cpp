// https://leetcode.com/problems/flood-fill/

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    auto inrange = [&](int i, int j) {
      return 0<=i && 0<=j && i<image.size() && j<image[0].size();
    };
    int base = image[sr][sc];
    if (base == newColor) return image;
    queue<pair<int,int>> q;
    q.emplace(sr, sc);
    int i, j;
    while (!q.empty()) {
      int n = q.size();
      while (n) {
        tie(i, j) = q.front();
        q.pop();
        image[i][j] = newColor;
        if (inrange(i-1, j) && image[i-1][j] == base) q.emplace(i-1, j);
        if (inrange(i+1, j) && image[i+1][j] == base) q.emplace(i+1, j);
        if (inrange(i, j-1) && image[i][j-1] == base) q.emplace(i, j-1);
        if (inrange(i, j+1) && image[i][j+1] == base) q.emplace(i, j+1);
        n--;
      }
    }
    return image;
  }
};