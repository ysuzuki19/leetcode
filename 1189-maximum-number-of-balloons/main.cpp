class Solution {
public:
  int maxNumberOfBalloons(string text) {
    int count_b = 0;
    int count_a = 0;
    int count_l = 0;
    int count_o = 0;
    int count_n = 0;
    for (const auto& c: text) {
      switch (c) {
        case 'b':
          count_b++;
          break;
        case 'a':
          count_a++;
          break;
        case 'l':
          count_l++;
          break;
        case 'o':
          count_o++;
          break;
        case 'n':
          count_n++;
          break;
      }
    }
    int minimum = count_b;
    minimum = min(minimum, count_a);
    minimum = min(minimum, count_l/2);
    minimum = min(minimum, count_o/2);
    minimum = min(minimum, count_n);
    return minimum;
  }
};