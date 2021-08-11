func bitmask(digit uint) uint {
	return 1 << digit
}

func checkbit(num uint, digit uint) bool {
	if num&bitmask(digit) != 0 {
		return true
	} else {
		return false
	}
}

func subsets(nums []int) [][]int {
	subsets := [][]int{}
	for i := uint(0); i < (1 << len(nums)); i++ {
		subset := []int{}
		for j := uint(0); j < uint(len(nums)); j++ {
			if checkbit(i, j) {
				subset = append(subset, nums[j])
			}
		}
		subsets = append(subsets, subset)
	}
	return subsets
}