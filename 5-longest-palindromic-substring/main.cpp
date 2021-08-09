class Solution {
public:
  string longestPalindrome(string s) {
    int subLeft = 0;
    int subRight = 0;
    int subSize = 0;
    auto update = [&](int left, int right){
      int nowSize = right - left + 1;
      if( subSize < nowSize ){
        subLeft = left;
        subRight = right;
        subSize = nowSize;
      }
    };
    for(size_t center=0; center<s.length(); ++center){
      if(s[center] != s[center+1]) continue;
      size_t left = center;
      size_t right = center + 1;
      while( left!=0 && right!=s.length()-1 ){
        if( s[left-1] != s[right+1] ) break;
        left--;
        right++;
      }
      update(left, right);
    }
    for(size_t center=0; center<s.length(); ++center){
      size_t left = center;
      size_t right = center;
      while( left!=0 && right!=s.length()-1 ){
        if( s[left-1] != s[right+1] ) break;
        left--;
        right++;
      }
      update(left, right);
    }
    return s.substr(subLeft, subSize);
  }
};