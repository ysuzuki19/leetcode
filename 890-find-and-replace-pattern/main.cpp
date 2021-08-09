class Solution {
  bool isAlphabet(char c) {
    return 'a' <= c && c <= 'z';
  }
  
  string convert(string str) {
    int count = 0;
    for (int i=0; i<str.length(); ++i) {
      char c = str[i];
      if (isAlphabet(c)) {
        for (int j=i; j<str.length(); ++j) {
          if (c == str[j]) str[j] = ('0' + count);
        }
        count ++;
      }
    }

    return str;
  }
  
public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    pattern = convert(pattern);
    
    vector<string> matches;
    for (auto &word: words) {
      if (convert(word) == pattern) {
        matches.push_back(word);
      }
    }
    
    return matches;
  }
};