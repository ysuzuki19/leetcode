// https://leetcode.com/problems/set-mismatch/

func findErrorNums(nums []int) []int {
	lut := make([]int, len(nums)+1)
	for _, num := range nums {
		lut[num]++
	}
	dup, loss := 0, 0
	for i, v := range lut {
		if v == 0 {
			loss = i
		}
		if v == 2 {
			dup = i
		}
	}
	return []int{dup, loss}
}