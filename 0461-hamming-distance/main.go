func countDigits(num int) int {
	digit := 0
	for num > 0 {
		num /= 2
		digit++
	}
	return digit
}

func bitmask(digit uint) uint {
	return 1 << digit
}

func bitDiff(x, y uint, digit uint) bool {
	x_true := (x&bitmask(digit) != 0)
	y_true := (y&bitmask(digit) != 0)
	if x_true != y_true {
		return true
	} else {
		return false
	}
}

func hammingDistance(x int, y int) int {
	max := x
	if max < y {
		max = y
	}
	digits := countDigits(max)
	dist := 0
	for i := 0; i < digits; i++ {
		if bitDiff(uint(x), uint(y), uint(i)) {
			dist++
		}
	}
	return dist
}