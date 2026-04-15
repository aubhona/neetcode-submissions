type Solution struct{}

func (s *Solution) Encode(strs []string) string {
	sb := strings.Builder{}

	sb.Grow(len(strs))

	for _, str := range strs {
		sb.WriteString(strconv.Itoa(len(str)))
		sb.WriteString("#")
		sb.WriteString(str)
	}

	return sb.String()
}

func (s *Solution) Decode(encoded string) []string {

	result := make([]string, 0, len(encoded))

	lenCounter := 0

	for i := 0; i < len(encoded); {
		lenCounter, i = GetLen(encoded, i)
		result = append(result, encoded[i:i + lenCounter])
		i += lenCounter
	}

	return result
}

func GetLen(str string, start int) (int, int) {
	end := start + 2

	for {
		subStr := str[start:end]

		isMatch, _ := regexp.MatchString(`\d+#`, subStr) 
		
		if isMatch {
			length, _ := strconv.Atoi(subStr[:len(subStr)-1])

			fmt.Println(length)

			return length, end
		}

		end++;
	} 
}
