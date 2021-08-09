class Solution {
  char toLowerCase(char c) {
    if ('A' <= c && c <= 'Z') return c + ('a' - 'A');
    return c;
  }
public:
  string toLowerCase(string s) {
    for (auto& c: s) {
      c = toLowerCase(c);
    }
    return s;
  }
};