func thirdMax(nums []int) int {
	sort.Ints(nums)
	count := 1
	before := nums[len(nums)-1]
	idx := len(nums) - 2
	for 0 <= idx {
		if before == nums[idx] {
			idx--
			continue
		}
		before = nums[idx]
		count++
		if count == 3 {
			return nums[idx]
		}
	}
	return nums[len(nums)-1]
}