class Solution {
public:
  string frequencySort(string s) {
    array<int, 'z'+1> counts;
    for (auto& e: counts) {
      e = 0;
    }
    for (const auto& c: s) {
      counts[c] ++;
    }
    sort(s.begin(), s.end(), [&](char a, char b) {
      if (counts[a] == counts[b]) {
        return a < b;
      }
      return counts[a] > counts[b];
    });
    return s;
  }
};