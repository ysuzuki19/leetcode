class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int,int>> rows;
    rows.reserve (mat.size ());
    for (const auto& vec : mat) {
      int count = 0;
      for (const auto& e : vec) {
        if (e) count++;
      }
      rows.emplace_back (rows.size (), count);
    }
    
    sort (rows.begin (), rows.end (), [](pair<int,int> left, pair<int,int> right) {
      // top-level compare (strong)
      if (left.second < right.second) return true;
      if (left.second > right.second) return false;
      // second-level compare (index of row)
      if (left.first < right.first) return true;
      return false;
    });
    
    vector<int> res;
    res.reserve (k);
    for (int i=0; i<k; ++i) {
      res.push_back (rows[i].first);
    }
    return res;
  }
};