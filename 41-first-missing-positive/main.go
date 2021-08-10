func firstMissingPositive(nums []int) int {
	st := make(map[int]bool)
	for _, num := range nums {
		st[num] = true
	}

	for i := 1; ; i++ {
		if found := st[i]; !found {
			return i
		}
	}
}