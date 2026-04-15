func binSearch(nums []int, target int) int {
	left, right := 0, len(nums) - 1

	for left <= right {
		mid := left + (right - left) / 2

		if target == nums[mid] {
			return mid
		}

		if target < nums[mid] {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return -1
}

func searchMatrix(matrix [][]int, target int) bool {
    left, right := 0, len(matrix) - 1

	ind := -1

	for left <= right {
		mid := left + (right - left) / 2

		if matrix[mid][0] == target {
			return true
		}

		if matrix[mid][0] <= target && target <= matrix[mid][len(matrix[mid]) - 1] {
			ind = mid
			break
		}

		if matrix[mid][0] > target {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	if ind == -1 {
		return false
	}

	return binSearch(matrix[ind], target) != -1
}
