func sortColors(nums []int) {
	loop := true
	for loop {
		loop = false
		for i := 1; i < len(nums); i++ {
			if nums[i-1] > nums[i] {
				nums[i-1], nums[i] = nums[i], nums[i-1]
				loop = true
			}
		}
	}
}