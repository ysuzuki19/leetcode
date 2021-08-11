func fizzBuzz(n int) []string {
	var strs []string
	for i := 1; i <= n; i++ {
		if i%3 == 0 && i%5 == 0 {
			strs = append(strs, "FizzBuzz")
			continue
		}
		if i%3 == 0 {
			strs = append(strs, "Fizz")
			continue
		}
		if i%5 == 0 {
			strs = append(strs, "Buzz")
			continue
		}
		strs = append(strs, strconv.Itoa(i))
	}
	return strs
}