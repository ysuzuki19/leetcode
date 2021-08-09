class Solution {
  int toInt(string s) {
    int num = 0;
    for (const auto& c: s) {
      num *= 10;
      num += (c - 'a');
    }
    return num;
  }
public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    return toInt(firstWord) + toInt(secondWord) == toInt(targetWord);
  }
};