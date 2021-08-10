func abs(num int) int {
	if num > 0 {
		return num
	} else {
		return -num
	}
}

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)

	closest := nums[0] + nums[1] + nums[2]
	diff := abs(closest - target)
	for i := range nums {
		for j := i + 1; j < len(nums); j++ {
			two_sum := nums[i] + nums[j]
			for k := j + 1; k < len(nums); k++ {
				three_sum := two_sum + nums[k]
				nowdiff := abs(three_sum - target)
				if nowdiff < diff {
					closest = three_sum
					diff = nowdiff
				}
			}
		}
	}
	return closest
}