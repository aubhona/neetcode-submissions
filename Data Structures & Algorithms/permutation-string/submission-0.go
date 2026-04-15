func checkInclusion(s1 string, s2 string) bool {
	size1 := len(s1)
	size2 := len(s2)

	if size1 > size2 {
		return false
	}

	var countMap [26]byte
	var lclMap [26]byte

	for _, c := range s1 {
		countMap[c - 'a']++
	}

	for i := 0; i < size1; i++ {
		lclMap[s2[i] - 'a']++
	} 

	if lclMap == countMap {
		return true
	}

	for left, right := 0, size1; right < size2; {
		lclMap[s2[left] - 'a']--
		lclMap[s2[right] - 'a']++

		if lclMap == countMap {
			return true
		}

		left++
		right++
	}

	return false
}
