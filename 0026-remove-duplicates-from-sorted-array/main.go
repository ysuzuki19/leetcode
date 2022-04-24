func removeDuplicates(nums []int) int {
	removed := []int{}
	for _, num := range nums {
		if len(removed) > 0 && removed[len(removed)-1] == num {
			continue
		}
		removed = append(removed, num)
	}
	remaining := len(removed)
	copy(nums, removed)
	return remaining
}