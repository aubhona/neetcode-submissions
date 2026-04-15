func twoSum(numbers []int, target int) []int {
	left, right := 0, len(numbers) - 1

	for ; left < right; {
		sum := numbers[left] + numbers[right]

		if sum < target {
			left++
			continue
		}

		if sum > target {
			right--
			continue
		}

		return []int{left + 1, right + 1}
	}
	
	return []int{}
}
