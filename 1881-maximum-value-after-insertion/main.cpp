class Solution {
public:
  string maxValue(string n, int x) {
    if (n[0] == '-') {
      for (int i=1; i<n.length(); ++i) {
        if (x+'0' < n[i]) {
          n.insert(i, to_string(x));
          return n;
        }
      }
    } else {
      for (int i=0; i<n.length(); ++i) {
        if (x+'0' > n[i]) {
          n.insert(i, to_string(x));
          return n;
        }
      }
    }
    n.insert(n.length(), to_string(x));
    return n;
  }
};