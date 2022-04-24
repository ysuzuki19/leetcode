class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> intersections;
    for(size_t i=0, j=0; i<A.size() && j<B.size(); A[i][1]<B[j][1]? i++:j++){
      int lo = max(A[i][0], B[j][0]), hi = min(A[i][1], B[j][1]);
      if( lo <= hi ) intersections.push_back({lo, hi});
    }
    return intersections;
  }
};