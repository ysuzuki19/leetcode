class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<pair<int, double>> squares(points.size());
    for(int i=0; i<points.size(); ++i){
      squares[i].first = i;
      squares[i].second = points[i][0]*points[i][0] + points[i][1]*points[i][1];
    }
    sort(squares.begin(), squares.end(), [](pair<int, double> a, pair<int, double> b){
      return a.second < b.second;
    });
    vector<vector<int>> closests(K, vector<int>(2));
    for(int i=0; i<K; ++i) closests[i] = points[squares[i].first];
    return closests;
  }
};