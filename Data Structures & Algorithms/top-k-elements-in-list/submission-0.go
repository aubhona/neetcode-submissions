/*
 * @lc app=leetcode id=347 lang=golang
 *
 * [347] Top K Frequent Elements
 */

import (
	"cmp"
	"maps"
	"slices"
)

// @lc code=start
func topKFrequent(nums []int, k int) []int {
    counterMap := make(map[int]int, len(nums))
	for _, num := range nums {
		counterMap[num]++
	}

	keys := slices.SortedFunc(maps.Keys(counterMap), func(i, j int) int {
		return cmp.Compare(counterMap[j], counterMap[i])
	}) 

	return keys[:k]
}
// @lc code=end

