class Solution {
public:
  int firstUniqChar(string s) {
    int collection['z'-'a'+1] = {0};
    for(const auto& c : s) collection[c-'a']++;
    for(int i=0; i<s.length(); ++i){
      if(collection[s[i]-'a']<2) return i;
    }
    return -1;
  }
};