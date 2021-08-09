class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if(nums.size() < 3) return {};
    map<int,int> mp;
    for(const auto& num : nums) mp[num]++;
    vector<vector<int>> threes;
    for(auto itr_i=mp.begin(); itr_i!=mp.end(); ++itr_i){
      itr_i->second--;
      for(auto itr_j=itr_i; itr_j!=mp.end(); ++itr_j){
        if( itr_j->second == 0 ) continue;
        itr_j->second--;
        int nums_k = - itr_i->first - itr_j->first;
        if( nums_k < itr_j->first ){
          itr_j->second++;
          break;
        }
        if( mp[nums_k] != 0 ){
          threes.push_back({itr_i->first, itr_j->first, nums_k});
        }
        itr_j->second++;
      }
      itr_i->second++;
    }
    return threes;
  }
};