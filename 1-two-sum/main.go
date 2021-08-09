func twoSum(nums []int, target int) []int {
	mp := make(map[int]int)
	for i, v := range nums {
		j, ok := mp[target-v]
		if ok {
			return []int{i, j}
		}
		mp[v] = i
	}
	return []int{-1, -1}
}