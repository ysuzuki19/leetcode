class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    if(ransomNote.empty()) return true;
    if(magazine.empty()) return false;
    int collections[26] = {0};
    for(const auto& c : magazine) collections[c-'a']++;
    for(const auto& c : ransomNote){
      collections[c-'a']--;
      if(collections[c-'a']<0) return false;
    }
    return true;
  }
};