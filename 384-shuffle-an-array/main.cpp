class Solution {
  private:
    vector<int> data_;
  public:
  Solution(vector<int>& nums): data_{nums} {}

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return data_;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> output (data_);
    std::random_shuffle(output.begin(), output.end());
    return output;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */