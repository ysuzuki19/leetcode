class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    vector<int> left_sums, right_sums;
    left_sums.reserve(nums.size() + 1);
    right_sums.reserve(nums.size() + 1);
    
    left_sums.push_back(0);
    for (int i=0; i<nums.size() && left_sums.back() <= x; ++i) {
      left_sums.push_back(left_sums.back() + nums[i]);
    }
    
    right_sums.push_back(0);
    for (int i=nums.size()-1; i>-1 && right_sums.back() <= x; --i) {
      right_sums.push_back(right_sums.back() + nums[i]);
    }
    
    int op = nums.size() + 1;
    int right = right_sums.size() - 1;
    
    for (int left=0; left<left_sums.size(); ++left) {
      for (;right>-1;--right) {
        int sum = left_sums[left] + right_sums[right];
        if (sum <= x) {
          if (sum == x) {
            op = min(op, left + right);
          }
          break;
        }
      }
    }
    
    if (op <= nums.size()) {
      return op;
    }
    
    return -1;
  }
};