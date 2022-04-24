// https://leetcode.com/problems/student-attendance-record-i/

func checkRecord(s string) bool {
	if len(s) < 2 {
		return true
	}
	absent := 0
	if s[0] == 'A' {
		absent++
	}
	if s[1] == 'A' {
		absent++
	}
	late := 0
	if s[0] == 'L' {
		late++
	}
	if s[1] == 'L' {
		late++
	}
	for i := 2; i < len(s); i++ {
		if s[i] == 'A' {
			absent++
		}
		if s[i] == 'L' {
			late++
		}
		if late > 2 {
			return false
		}
		if s[i-2] == 'L' {
			late--
		}
	}
	if absent < 2 {
		return true
	}
	return false
}