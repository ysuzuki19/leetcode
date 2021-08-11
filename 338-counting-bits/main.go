func countDigits(n int) int {
	count := 1
	for n > 0 {
		n /= 2
		count++
	}
	return count
}

func bitmask(digit uint) uint {
	return 1 << digit
}

func checkbit(num uint, digit uint) bool {
	if num&bitmask(digit) != 0 {
		return true
	} else {
		return false
	}
}

func countBit(num int) int {
	count := 0
	for i := 0; i < (countDigits(num)); i++ {
		if checkbit(uint(num), uint(i)) {
			count++
		}
	}
	return count
}

func countBits(n int) []int {
	var bits []int
	for i := 0; i <= n; i++ {
		bits = append(bits, countBit(i))
	}
	return bits
}