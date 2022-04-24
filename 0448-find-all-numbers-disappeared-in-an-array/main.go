func findDisappearedNumbers(nums []int) []int {
	mp := make(map[int]bool)
	for _, v := range nums {
		mp[v] = true
	}
	var dis []int
	for i := 1; i <= len(nums); i++ {
		if !mp[i] {
			dis = append(dis, i)
		}
	}
	return dis
}