func singleNonDuplicate(nums []int) int {
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] != nums[i+1] {
			return nums[i]
		}
		for i < len(nums)-1 && nums[i] == nums[i+1] {
			i++
		}
	}
	return nums[len(nums)-1]
}