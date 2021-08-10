func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return make([]string, 0)
	}
	keymap := []string{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

	letters := []string{""}
	for i := 0; i < len(digits); i++ {
		var newletters []string
		for j := 0; j < len(keymap[digits[i]-'2']); j++ {
			newsubletters := make([]string, len(letters))
			copy(newsubletters, letters)
			for k := 0; k < len(newsubletters); k++ {
				newsubletters[k] += string(keymap[digits[i]-'2'][j])
			}
			newletters = append(newletters, newsubletters...)
		}
		letters = newletters
	}
	return letters
}