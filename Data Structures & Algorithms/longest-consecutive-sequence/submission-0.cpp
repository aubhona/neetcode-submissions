
#include <unordered_map>
#include <vector>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        std::unordered_map<int, int> union_set;
        union_set.reserve(nums.size());

        for (const auto num : nums) {
            if (!union_set.count(num)) {
                union_set[num] = num;
            }
        }

        for (const auto num : nums) {
            if (union_set.count(num + 1)) {
                union_set[find(union_set, num)] = find(union_set, num + 1);
            }
        }

        std::unordered_map<int, int> freq;
        freq.reserve(union_set.size());

        for (const auto& [key, _] : union_set) {
            ++freq[find(union_set, key)];
        }

        auto most_frequent = std::max_element(
        freq.begin(),
        freq.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        }
        );

        return most_frequent->second;
    }


    int find(std::unordered_map<int, int>& union_set, int num) {
        if (union_set[num] == num) {
            return num;
        }

        union_set[num] = find(union_set, union_set[num]);

        return union_set[num];
    }
};