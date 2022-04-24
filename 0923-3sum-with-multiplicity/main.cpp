class Solution {
  static constexpr int moduler = 1000000000 + 7;
  int ncr (int n, int r) {
    unsigned long long x = 1;
    for (int i=0; i<r; ++i) {
      x *= (n-i);
      x /= (1+i);
      x %= moduler;
    }
    return x;
  }
public:
  int threeSumMulti(vector<int>& arr, int target) {
    map<int,int> mp;
    for (const auto& e : arr) {
      if (mp.find(e) == mp.end()) {
        mp.emplace(e, 1);
      } else {
        mp[e]++;
      }
    }
    
    unsigned long long pat = 0;
    for (auto itr=mp.begin(); itr!=mp.end(); ++itr) {
      itr->second--;
      for (auto jtr=itr; jtr!=mp.end(); ++jtr) {
        if (jtr->second == 0) continue;
        jtr->second --;
        
        auto found = mp.find(target-itr->first-jtr->first);
        if (found != mp.end() && found->second && found->first >= jtr->first) {
          if (jtr->first == found->first) {
            if (itr->first == jtr->first) {
              pat += ncr(itr->second + 2, 3);
            } else {
              pat += (itr->second + 1) * ncr(jtr->second + 1, 2);
            }
          } else {
            if (itr->first == jtr->first) {
              pat += ncr(itr->second + 2, 2) * found->second;
            } else {
              pat += (itr->second + 1) * (jtr->second + 1) * found->second;
            }
          }
        }
        pat %= moduler;
        jtr->second ++;
      }
      while (itr->second) itr->second --;
    }
    return static_cast<int>(pat);
  }
};