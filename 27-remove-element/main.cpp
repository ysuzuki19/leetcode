class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    vector<int> new_nums;
    new_nums.reserve (nums.size ());
    for (const auto& num : nums) {
      if (num != val) new_nums.push_back (num);
    }
    nums = std::move (new_nums);
    return nums.size ();
  }
};