func myPow(x float64, n int) float64 {
	if n == 0 {
		return 1
	}
	if n > 0 {
		if n == 1 {
			return x
		}
		half := n / 2
		remd := n % 2
		half_pow := myPow(x, half)
		if remd == 0 {
			return half_pow * half_pow
		} else {
			return half_pow * half_pow * x
		}
	} else {
		if n == -1 {
			return 1.0 / x
		}
		half := n / 2
		remd := n % 2
		half_pow := myPow(x, -half)
		if remd == 0 {
			return 1.0 / (half_pow * half_pow)
		} else {
			return 1.0 / (half_pow * half_pow * x)
		}
	}
}