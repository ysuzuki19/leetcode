class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end());
    if (h != horizontalCuts.back()) horizontalCuts.push_back(h);
    sort(verticalCuts.begin(), verticalCuts.end());
    if (w != verticalCuts.back()) verticalCuts.push_back(w);
    
    long max_hor_diff = horizontalCuts[0];
    for (int i=1; i<horizontalCuts.size(); ++i) {
      max_hor_diff = max(max_hor_diff, static_cast<long>(horizontalCuts[i] - horizontalCuts[i-1]));
    }
    
    long max_ver_diff = verticalCuts[0];
    for (int i=1; i<verticalCuts.size(); ++i) {
      max_ver_diff = max(max_ver_diff, static_cast<long>(verticalCuts[i] - verticalCuts[i-1]));
    }
    return static_cast<int>((max_hor_diff * max_ver_diff) % 1000000007);
  }
};