class Solution {
  map<int,int> createMemo(vector<int> const& nums) {
    map<int,int> memo;
    for (const auto& num: nums) {
      auto found = memo.find(num);
      if (found != memo.end()) {
        found->second ++;
      } else {
        memo[num] = 1;
      }
    }
    return move(memo);
  }
  map<int,int> createUses(vector<int> const& nums) {
    map<int,int> uses;
    for (const auto& num: nums) {
      auto found = uses.find(num);
      if (found == uses.end()) {
        uses[num] = 0;
      }
    }
    return move(uses);
  }
  vector<int> createSubset(map<int,int> const& uses) {
    vector<int> subset;
    for (const auto& e: uses) {
      for (int i=0; i<e.second; ++i) {
        subset.push_back(e.first);
      }
    }
    return move(subset);
  }
  
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    if (nums.size() == 1) {
      return {{}, {nums[0]}};
    }
    auto memo = createMemo(nums);
    auto uses = createUses(nums);
    
    vector<vector<int>> subsets;
    function<void(map<int,int>::iterator)> recurser;
    recurser = [&](map<int,int>::iterator itr) {
      subsets.emplace_back(createSubset(uses));
      for (; itr!=memo.end(); ++itr) {
        if (0 < itr->second) {
          itr->second--;
          uses[itr->first]++;
          if (itr->second == 0) {
            recurser(itr++);
            itr--;
          } else {
            recurser(itr);
          }
          uses[itr->first]--;
          itr->second++;
        }
      }
    };
    recurser(memo.begin());
    return subsets;
  }
};