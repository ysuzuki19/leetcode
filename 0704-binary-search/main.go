// https://leetcode.com/problems/binary-search/

func search(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left+1 < right {
		center := (left + right) / 2
		if nums[center] == target {
			return center
		}
		if nums[center] < target {
			left = center
		} else {
			right = center
		}
	}
	if nums[left] == target {
		return left
	}
	if nums[right] == target {
		return right
	}
	return -1
}