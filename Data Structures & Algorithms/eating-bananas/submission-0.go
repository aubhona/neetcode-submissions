/*
 * @lc app=leetcode id=875 lang=golang
 *
 * [875] Koko Eating Bananas
 */


import (
	"slices"
)

// @lc code=start
func minEatingSpeed(piles []int, h int) int {
	if len(piles) == h {
        return slices.Max(piles) 
    }

    left, right := 1, slices.Max(piles)
	result := 1
	
	for left <= right {
		mid := left + (right - left) / 2

		if canEatAll(piles, mid, h) {
			right = mid - 1
			result = mid
		} else {
			left = mid + 1
		}
	}

	return result
}

func canEatAll(piles []int, k int, h int) bool {
    total := 0

    for _, p := range piles {
        total += (p + k - 1) / k

        if total > h {
            return false
        }
    }

    return total <= h
}
// @lc code=end

