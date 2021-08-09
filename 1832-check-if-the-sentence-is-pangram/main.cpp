class Solution {
public:
  bool checkIfPangram(string sentence) {
    array<bool, 26> pan;
    for (auto& p: pan) p = false;
    for (const auto& c: sentence) {
      pan[c-'a'] = true;
    }
    for (const auto& p: pan) {
      if (!p) return false;
    }
    return true;
  }
};