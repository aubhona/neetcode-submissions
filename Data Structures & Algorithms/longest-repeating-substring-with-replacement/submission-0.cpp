class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int count_map[26] = {};

        auto max_count = 0;
        auto left= 0;
        auto right = k;

        for (size_t i = 0; i < right; ++i) {
            auto& count = count_map[s[i] - 'A'];

            ++count;
            
            if (count > max_count)
            {
                max_count = count;
            }
        }

        while (right != s.size()) {
            const auto ind = s[right] - 'A';

            auto& count = count_map[ind];

            ++count;

            if (count > max_count) {
                max_count = count; 
            }

            if (right - left + 1 - max_count > k) {
                const auto ind = s[left++] - 'A';

                auto& count = count_map[ind];

                --count;
            }
            ++right;
        }

        return right - left;
    }
};
