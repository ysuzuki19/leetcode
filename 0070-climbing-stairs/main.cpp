class Solution {
public:
  int climbStairs(int n) {
    vector<int> lut(n+1, 0);
    lut[0] = lut[1] = 1;
    function<int(int)> recurser;
    recurser = [&recurser, &lut](int n) {
      if (n < 0) return 0;
      if (!lut[n]) lut[n] = recurser(n-1) + recurser(n-2);
      return lut[n];
    };
    return recurser(n);
  }
};