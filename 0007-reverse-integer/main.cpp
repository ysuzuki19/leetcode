class Solution {
public:
  int reverse(int x) {
    long xRev = 0;
    while(true){
      xRev += x%10;
      x /= 10;
      if( x == 0 ) break;
      else xRev *= 10;
    }
    if(xRev < INT_MIN || xRev > INT_MAX) return 0;
    return xRev;
  }
};