use std::collections::HashSet;

impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let mut maximum: i32 = 0;
        let mut inner: i32 = 0;
        let mut set = HashSet::<i32>::new();
        let mut l = 0;
        let mut r = 0;
        while r < nums.len() {
            while l < nums.len() && l <= r {
                if set.contains(&nums[r]) {
                    set.remove(&nums[l]);
                    inner -= nums[l];
                } else {
                    break;
                }
                l += 1;
            }
            set.insert(nums[r]);
            inner += nums[r];
            if maximum < inner {
                maximum = inner;
            }
            r += 1;
        }
        return maximum;
    }
}
