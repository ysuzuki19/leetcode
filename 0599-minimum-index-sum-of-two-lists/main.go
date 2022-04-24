// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

func findRestaurant(list1 []string, list2 []string) []string {
	mp := make(map[string]int)
	for i, v := range list2 {
		mp[v] = i
	}
	mp2 := make(map[string]int)
	for i, v := range list1 {
		if e, ok := mp[v]; ok {
			mp2[v] = e + i
		}
	}

	var mins []string
	minimum := len(list1) + len(list2)
	for _, v := range mp2 {
		if v < minimum {
			minimum = v
		}
	}
	for k, v := range mp2 {
		if v == minimum {
			mins = append(mins, k)
		}
	}
	return mins
}