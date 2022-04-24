class Solution {
  bool withinRange(int size, int i, int j) {
    if (i<0 || size<=i) return false;
    if (j<0 || size<=j) return false;
    return true;
  }
  
  void preprocess(vector<vector<int>>& grid, map<int,int>& islands) {
    for (auto& row: grid) {
      for (auto& e: row) {
        if (e) e = -1;
      }
    }
    
    queue<pair<int,int>> q;
    int id = 0;
    for (int i=0; i<grid.size(); ++i) {
      for (int j=0; j<grid[i].size(); ++j) {
        if (grid[i][j] == -1) {
          id++;
          q.emplace(i,j);
          grid[i][j] = id;
          
          int land = 0;
          while (!q.empty()) {
            int n = q.size();
            while (n) {
              int k,l;
              tie(k,l) = q.front();
              q.pop();
              n--;
              land++;
              if (withinRange(grid.size(), k-1, l) && grid[k-1][l] == -1) {
                q.emplace(k-1,l);
                grid[k-1][l] = id;
              }
              if (withinRange(grid.size(), k+1, l) && grid[k+1][l] == -1) {
                q.emplace(k+1,l);
                grid[k+1][l] = id;
              }
              if (withinRange(grid.size(), k, l-1) && grid[k][l-1] == -1) {
                q.emplace(k,l-1);
                grid[k][l-1] = id;
              }
              if (withinRange(grid.size(), k, l+1) && grid[k][l+1] == -1) {
                q.emplace(k,l+1);
                grid[k][l+1] = id;
              }
            }
          }
          islands[id] = land;
        }
      }
    }
  }
public:
  int largestIsland(vector<vector<int>>& grid) {
    map<int,int> islands;
    preprocess(grid, islands);
    
    int maximum = 0;
    
    for (int i=0; i<grid.size(); ++i) {
      for (int j=0; j<grid[i].size(); ++j) {
        set<int> neighbors;
        int myid = grid[i][j];
        if (myid) neighbors.insert(myid);
        if (withinRange(grid.size(), i-1, j) && grid[i-1][j]) neighbors.insert(grid[i-1][j]);
        if (withinRange(grid.size(), i+1, j) && grid[i+1][j]) neighbors.insert(grid[i+1][j]);
        if (withinRange(grid.size(), i, j-1) && grid[i][j-1]) neighbors.insert(grid[i][j-1]);
        if (withinRange(grid.size(), i, j+1) && grid[i][j+1]) neighbors.insert(grid[i][j+1]);
        int land = myid? 0: 1;
        for (const auto& n: neighbors) {
          land += islands[n];
        }
        maximum = max(maximum, land);
      }
    }
    return maximum;
  }
};