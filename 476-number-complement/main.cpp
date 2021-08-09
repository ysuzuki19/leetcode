class Solution {
public:
  int findComplement(int num) {
    int bitFlip = 0;
    int bitLocate = 0;
    while(num!=0){
      if( !(num&1) ) bitFlip += (1<<bitLocate);
      num >>= 1;
      bitLocate++;
    }
    return bitFlip;
  }
};