class Solution {
  int lut[26];
  bool isLower(string const& a, string const& b) {
    for (int i=0; i<a.length() || i<b.length(); ++i) {
      if (i==a.length()) return false;
      if (i==b.length()) return true;
      if (lut[a[i]-'a'] < lut[b[i]-'a']) return false;
      if (lut[a[i]-'a'] > lut[b[i]-'a']) return true;
    }
    return false;
  }
public:
  bool isAlienSorted(vector<string>& words, string order) {
    for (int i=0; i<order.length(); ++i) {
      lut[order[i] - 'a'] = i;
    }
    
    for (int i=1; i<words.size(); ++i) {
      if (isLower(words[i-1], words[i])) {
        return false;
      }
    }
    return true;
  }
};