import "slices"

func threeSum(nums []int) [][]int {
    slices.Sort(nums)

	result := [][]int{}

	for ind, num := range nums {
		if num > 0 {
			break
		}

		if ind > 0 && num == nums[ind-1] {
			continue
		}

		result = findTwoSum(result, nums[ind+1:], -num)
	}

	return result
}


func findTwoSum(result [][]int, numbers []int, target int) [][]int {
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

		result = append(result, []int{-target, numbers[left], numbers[right]})

		left++
		right--

		for left < right && numbers[left] == numbers[left-1] {
			left++
		}
		for left < right && numbers[right] == numbers[right+1] {
			right--
		}
	}
	
	return result
}
