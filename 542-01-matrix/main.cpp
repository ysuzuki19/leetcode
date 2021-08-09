class Solution {
  bool withinRange(vector<vector<int>> const& mat, int i, int j) {
    if (i < 0) return false;
    if (j < 0) return false;
    if (mat.size() <= i) return false;
    if (mat[0].size() <= j) return false;
    return true;
  }
  
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

    vector<vector<int>> distances(mat.size(), vector<int>(mat[0].size(), -1));
    queue<pair<int,int>> q;
    for (int i=0; i<mat.size(); ++i) {
      for (int j=0; j<mat[i].size(); ++j) {
        if (mat[i][j] == 0) {
          distances[i][j] = 0;
          if (withinRange(mat, i-1, j) && mat[i-1][j] != 0) q.emplace(i-1, j); 
          if (withinRange(mat, i+1, j) && mat[i+1][j] != 0) q.emplace(i+1, j); 
          if (withinRange(mat, i, j-1) && mat[i][j-1] != 0) q.emplace(i, j-1); 
          if (withinRange(mat, i, j+1) && mat[i][j+1] != 0) q.emplace(i, j+1); 
        }
      }
    }
    
    int distance = 1;
    int i, j;
    while(!q.empty()) {
      int n = q.size();
      while (n) {
        tie(i, j) = q.front();
        if (distances[i][j] < 0) distances[i][j] = distance;
        
        if (withinRange(distances, i-1, j) && distances[i-1][j] < 0) q.emplace(i-1, j); 
        if (withinRange(distances, i+1, j) && distances[i+1][j] < 0) q.emplace(i+1, j); 
        if (withinRange(distances, i, j-1) && distances[i][j-1] < 0) q.emplace(i, j-1); 
        if (withinRange(distances, i, j+1) && distances[i][j+1] < 0) q.emplace(i, j+1); 
        
        n--;
        q.pop();
      }
      distance++;
    }
    
    return distances;
  }
};