func findDuplicates(nums []int) []int {
	var dup []int
	mp := make(map[int]bool)
	for _, e := range nums {
		if mp[e] {
			dup = append(dup, e)
		}
		mp[e] = true
	}
	return dup
}