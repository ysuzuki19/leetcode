// https://leetcode.com/problems/valid-parenthesis-string/

func checkValidString(s string) bool {
	low, high := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			low++
			high++
		} else if s[i] == ')' {
			if low > 0 {
				low--
			}
			high--
		} else { // s[i] == '*'
			if low > 0 {
				low--
			}
			high++
		}
		if high < 0 {
			return false
		}
	}
	return low == 0
}