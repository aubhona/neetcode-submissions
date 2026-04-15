func minWindow(s string, t string) string {
    if len(s) < len(t) {
        return ""
    }

    var tMap [128]int
    var foundMap [128]int

    for i := 0; i < len(t); i++ {
        tMap[t[i]]++
    }

    neededMatches := 0
    for _, v := range tMap {
        if v > 0 {
            neededMatches++
        }
    }

    filtered := make([]int, 0, len(s))
    for i := 0; i < len(s); i++ {
        if tMap[s[i]] > 0 {
            filtered = append(filtered, i)
        }
    }

    matches := 0
    resultLeft, resultRight := 0, -1

    for left, right := 0, 0; right < len(filtered); right++ {
        ch := s[filtered[right]]
        foundMap[ch]++
        if foundMap[ch] == tMap[ch] {
            matches++
        }

        for ; matches == neededMatches && left <= right; left++ {
            rIdx := filtered[right]
            lIdx := filtered[left]

            if resultRight == -1 || rIdx-lIdx < resultRight-resultLeft {
                resultLeft = lIdx
                resultRight = rIdx
            }

            lch := s[lIdx]
            foundMap[lch]--
            if foundMap[lch] < tMap[lch] {
                matches--
            }
        }
    }

    if resultRight == -1 {
        return ""
    }

    return s[resultLeft : resultRight+1]
}
