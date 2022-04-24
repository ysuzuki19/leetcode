class Solution {
public:
  int totalFruit(vector<int>& tree) {
    unordered_map<int,int> mp;
    int left = 0;
    int right = 0;
    int maximum = 0;
    while( right != tree.size() ){
      for(; mp.size() > 2 && left != right; ++left ){
        int key = tree[left];
        mp[key]--;
        if(mp.count(key) > 0 && mp[key] == 0) mp.erase(key);
      }
      for(; mp.size() != 3 && right != tree.size(); ++right ){
	    int key = tree[right];
        mp[key]++;
      }
      int produces = 0;
      for(const auto& e : mp) produces += e.second;
      if( right == tree.size() && mp.size() < 3 ) return max(maximum, produces);
      maximum = max(maximum, produces-1);
    }
    return maximum;
  }
};