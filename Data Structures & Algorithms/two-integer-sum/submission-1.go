func twoSum(nums []int, target int) []int {
    numsMap := make(map[int]int)

	for ind0, num := range nums {
		ind1, ok := numsMap[target - num]
		
		if !ok {
			numsMap[num] = ind0
			continue
		}

		return []int{ind1, ind0}
	}

	return []int{}
}
