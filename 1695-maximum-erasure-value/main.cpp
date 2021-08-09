class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int score = 0;
    unordered_set<int> collection;
    int subscore = 0;
    vector<int>::const_iterator left = nums.begin();
    for (const auto& right: nums) {
      auto found = collection.find(right);
      if (found == collection.end()) {
        collection.insert(right);
      } else {
        for (; *left!=right; left++) {
          subscore -= *left;
          collection.erase(*left);
        }
        subscore -= *left;
        left++;
      }
      subscore += right;
      score = max(score, subscore);
    }
    return score;
  }
};