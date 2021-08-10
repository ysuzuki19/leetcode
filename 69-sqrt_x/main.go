// https://leetcode.com/problems/sqrtx/
func mySqrt(x int) int {
	left, right := 0.0, float64(x*2)
	for right-left > 0.00001 {
		center := (left + right) / 2.0
		cc := center * center
		if float64(x) < cc {
			right = center
		} else {
			left = center
		}
	}
	return int(right)
}