class Solution {
public:
  int countBinarySubstrings(string s) {
    int counter = 0;
    
    for (int i=1; i<s.length(); ++i) {
      if (s[i-1]!= s[i]) {
        for (int j=0; 0<i-j && i+j<s.length(); ++j) {
          if (s[i-1-j] != s[i-1]) break;
          if (s[i+j] != s[i]) break;
          counter ++;
        }
      }
    }
    return counter;
  }
};