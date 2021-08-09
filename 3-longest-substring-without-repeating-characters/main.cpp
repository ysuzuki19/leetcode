class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    if (s.length() == 1) return 1;
    array<bool, CHAR_MAX> lut {{false}};
    
    int left = 0, right = 0;
    int longest = 1;
    int length = 0;
    while (right != s.length()) {
      while (lut[s[right]]) {
        lut[s[left]] = false;
        length--;
        left++;
      }
      lut[s[right]] = true;
      length++;
      
      if (longest < length) longest = length;
      right ++;
    }
    return longest;
  }
};