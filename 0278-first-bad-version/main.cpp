// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    unsigned int low = 0;
    unsigned int high = n;
    while( high-low > 1){
      unsigned int center = ( low + high ) / 2;
      if( isBadVersion(center) ) high = center;
      else                        low = center;
    }
    return high;
  }
};