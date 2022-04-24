class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    if(strs.size()==1) return strs[0];
    size_t minLength = strs[0].length();
    for(size_t i=1; i<strs.size(); ++i) minLength = min(minLength, strs[i].length());
    for(size_t i=0; i<minLength; ++i){
      for(size_t strIdx=1; strIdx<strs.size(); ++strIdx){
        if(strs[0][i] != strs[strIdx][i]) return strs[0].substr(0,i);
      }
    }
    return strs[0].substr(0,minLength);
  }
};