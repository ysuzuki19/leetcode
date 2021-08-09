class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};
    
    int left = 0;
    int right = nums.size() - 1;
    while (left + 1 < right) {
      int center = left + (right - left)/2;
      if (nums[center] == target) {
        left = center;
        break;
      }
      if (nums[center] < target) {
        left = center;
      } else {
        right = center;
      }
    }
    
    if (nums[left] == target) {
      right = left;
    } else {
      left = right;
    }
    
    if (nums[left] != target) {
      return {-1, -1};
    }
    
    while (left != 0 && nums[left-1] == target) {
      left--;
    }
    while (right != nums.size()-1 && nums[right+1] == target) {
      right++;
    }
    return {left, right};
  }
};