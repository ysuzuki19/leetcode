impl Solution {
    pub fn min_operations(nums: Vec<i32>, x: i32) -> i32 {
        let mut left_sums = Vec::<i32>::with_capacity(nums.len());
        left_sums.push(0);
        for num in nums.iter() {
            left_sums.push(left_sums.last().unwrap() + num);
        }

        let mut right_sums = Vec::<i32>::with_capacity(nums.len());
        right_sums.push(0);
        for num in nums.iter().rev() {
            right_sums.push(right_sums.last().unwrap() + num);
        }

        let mut right = (right_sums.len() - 1) as i32;
        let mut op = (nums.len() + 1) as i32;

        left_sums.iter().enumerate().for_each(|(i, le)| {
            let left = i as i32;
            while right != -1 {
                let sum = le + right_sums[right as usize];
                if sum <= x {
                    if sum == x {
                        if op > left + right {
                            op = left + right;
                        }
                    }
                    break;
                }
                right -= 1;
            }
        });

        if (op <= nums.len() as i32) {
            return op;
        }

        return -1;
    }
}
