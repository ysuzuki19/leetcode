use std::cmp;

impl Solution {
  pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
    let mut cnt:i32 = 0;
    let mut max:i32 = 0;
    for num in nums {
      match num {
        0 => {
          if max < cnt {
            max = cnt;
          }
          cnt = 0;
        },
        1 => {
          cnt += 1;
        },
        _ => println!("not match")
      }
    }
    cmp::max(cnt, max)
  }
}