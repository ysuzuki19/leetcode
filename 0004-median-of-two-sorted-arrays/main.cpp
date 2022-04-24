class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums;
    nums.reserve(nums1.size() + nums2.size());
    size_t i=0, j=0;
    while( i<nums1.size() && j<nums2.size() ){
      if( nums1[i] < nums2[j] ) nums.push_back(nums1[i++]);
      else nums.push_back(nums2[j++]);
    }
    while( i<nums1.size() ) nums.push_back(nums1[i++]);
    while( j<nums2.size() ) nums.push_back(nums2[j++]);
    if(nums.size() % 2) return nums[nums.size()/2];
    else return ( nums[nums.size()/2] + nums[nums.size()/2-1] ) /2.0;
    return 0;
  }
};