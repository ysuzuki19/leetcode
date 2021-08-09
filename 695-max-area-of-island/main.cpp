class Solution {
  struct Pos {
    int x = 0;
    int y = 0;
    Pos () = default;
    Pos (int x_, int y_) : x{x_}, y{y_} {}
  };
  bool withinField (vector<vector<int>> const& grid, Pos pos) {
    if (pos.x < 0) return false;
    if (pos.y < 0) return false;
    if (pos.x > grid.size()-1) return false;
    if (pos.y > grid.front().size()-1) return false;
    return true;
  }
  bool isIsland (vector<vector<int>> const& grid, Pos pos) {
    bool status = (grid[pos.x][pos.y] == 1);
    return status;
  }
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    //NOTICE: grid[i][j] = -1 means [i][j] is event searched.
    int count = 0;
    queue<Pos> q;
    for (int i=0; i<grid.size(); ++i) {
      for (int j=0; j<grid[i].size(); ++j) {
        int subcount = 0;
        if (grid[i][j] == 1) {
          grid[i][j] = -1;
          q.emplace(i, j);
        }
        while (!q.empty()) {
          Pos pos;
          pos = q.front();
          pos.x -= 1;
          if (withinField(grid, pos) && isIsland(grid, pos)) {
            grid[pos.x][pos.y] = -1;
            q.push(pos);
          }
          pos.x += 1;
          pos.y -= 1;
          if (withinField(grid, pos) && isIsland(grid, pos)) {
            grid[pos.x][pos.y] = -1;
            q.push(pos);
          }
          pos.x += 1;
          pos.y += 1;
          if (withinField(grid, pos) && isIsland(grid, pos)) {
            grid[pos.x][pos.y] = -1;
            q.push(pos);
          }
          pos.x -= 1;
          pos.y += 1;
          if (withinField(grid, pos) && isIsland(grid, pos)) {
            grid[pos.x][pos.y] = -1;
            q.push(pos);
          }
          subcount++;
          q.pop();
        }
        count = max(count, subcount);
      }
    }
    return count;
  }
};