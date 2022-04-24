// https://leetcode.com/problems/find-k-closest-elements/

func distance(num, x int) int {
	diff := num - x
	if diff < 0 {
		return -diff
	}
	return diff
}

func findClosestElements(arr []int, k int, x int) []int {
	left, right := 0, k
	for right < len(arr) {
		if arr[left] != arr[right] && distance(arr[left], x) <= distance(arr[right], x) {
			break
		}
		left++
		right++
	}
	return arr[left:right]
}