func lengthOfLongestSubstring(s string) int {
	var charIndex [256]int

	left, right, maxLen := 0, 0, 0

	for ; right < len(s); right++ {
		sym := s[right]
		indexOfSym := charIndex[sym]

		if indexOfSym >= left+1 {
			maxLen = max(right-left, maxLen)
			left = indexOfSym
		}

		charIndex[sym] = right + 1
	}

	maxLen = max(right-left, maxLen)

	return maxLen
}
