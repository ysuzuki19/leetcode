func addBinary(a string, b string) string {
	la := list.New()
	for _, c := range a {
		la.PushBack(c - '0')
	}
	lb := list.New()
	for _, c := range b {
		lb.PushBack(c - '0')
	}

	output := ""
	up := false
	for la.Len() > 0 && lb.Len() > 0 {
		laback := la.Back()
		lbback := lb.Back()

		added := laback.Value.(int32) + lbback.Value.(int32)
		if up {
			added++
			up = false
		}
		if added > 1 {
			up = true
			added -= 2
		}

		output = string(added+'0') + output
		la.Remove(laback)
		lb.Remove(lbback)
	}

	for la.Len() > 0 {
		laback := la.Back()

		added := laback.Value.(int32)
		if up {
			added++
			up = false
		}
		if added > 1 {
			up = true
			added -= 2
		}
		output = string(added+'0') + output
		la.Remove(laback)
	}

	for lb.Len() > 0 {
		lbback := lb.Back()

		added := lbback.Value.(int32)
		if up {
			added++
			up = false
		}
		if added > 1 {
			up = true
			added -= 2
		}
		output = string(added+'0') + output
		lb.Remove(lbback)
	}

	if up {
		output = string('1') + output
	}

	return output
}