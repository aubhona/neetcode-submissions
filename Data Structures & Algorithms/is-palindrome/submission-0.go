func isPalindrome(s string) bool {
    left := 0
	right := len(s) -1

	for ; left < right; {
		leftChar := unicode.ToLower(rune(s[left]))

		if !unicode.IsLetter(leftChar) && !unicode.IsDigit(leftChar) {
			left++;
			continue;
		}

		rightChar := unicode.ToLower(rune(s[right]))

		if !unicode.IsLetter(rightChar) && !unicode.IsDigit(rightChar) {
			right--;
			continue;
		}

		if leftChar == rightChar {
			left++
			right--
			continue
		}

		return false
	}

	return true
}
