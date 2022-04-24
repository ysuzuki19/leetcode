class Solution {
  int maxArea(vector<int>::const_iterator left, vector<int>::const_iterator right) {
    if (left == right) return 0;
    int container_water = (right - left) * min (*left, *right);
    if (*left < *right) {
      return max (container_water, maxArea (left + 1, right));
    } else {
      return max (container_water, maxArea (left, right - 1));
    }
  }
public:
  int maxArea(vector<int>& height) {
    return maxArea (height.begin (), height.end () - 1);
  }
};