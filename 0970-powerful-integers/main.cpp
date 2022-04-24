class Solution {
public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    vector<int> xs;
    xs.push_back(1);
    if (x != 1) {
      for (int xi = x; xi < bound; xi*=x) {
        xs.push_back(xi);
      }
    }
    
    vector<int> ys;
    ys.push_back(1);
    if (y != 1) {
      for (int yi = y; yi < bound; yi*=y) {
        ys.push_back(yi);
      }
    }
    
    set<int> st;
    for (const auto& xi: xs) {
      for (const auto& yi: ys) {
        if (xi+yi > bound) break;
        if (st.find(xi+yi) == st.end()) st.insert(xi+yi);
      }
    }
    
    vector<int> nums;
    nums.reserve(st.size());
    for (const auto& e: st) nums.push_back(e);
    
    return nums;
  }
};