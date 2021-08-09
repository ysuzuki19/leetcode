class Solution {
  public int lengthOfLongestSubstring(String s) {
    boolean[] lut = new boolean[256]; // java learn
    int left = 0, right = 0;
    int longest = 0;
    while (right != s.length()) { // java learn
      while (lut[s.charAt(right)]) { //java learn
        lut[s.charAt(left)] = false;
        left++;
      }
      lut[s.charAt(right)] = true;
      
      longest = Math.max(longest, right - left + 1); //java learn
      
      right++;
    }
    return longest;
  }
}