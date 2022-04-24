class Solution {
public:
  int trap(vector<int>& height) {
    if(height.size() < 2) return 0;
    
    vector<int> right_max (height.size());
    right_max.back() = height.back();
    for (int i=height.size()-2; i!=-1; --i) {
      right_max[i] = max(right_max[i+1], height[i]);
    }
    
    int left_max = height[0];
    int trapped_water = 0;
    for (int i=1; i<height.size()-1; ++i) {
      int min_wall = min(left_max, right_max[i+1]);
      int water = min_wall - height[i];
      if (water > 0) trapped_water += water;
      left_max = max(left_max, height[i]);
    }
    
    return trapped_water;
  }
};