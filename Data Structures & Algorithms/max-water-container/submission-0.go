func maxArea(height []int) int {
	left, right := 0, len(height)-1
	maxVolume := -1

	for left < right {
		maxVolume = max(maxVolume, (right-left)*min(height[left], height[right]))

		if height[left] < height[right] {
			left++
		} else {
			right--
		}
	}

	return maxVolume
}
