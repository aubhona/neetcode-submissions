/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <unordered_map>
#include <vector>
#include <array>

// @lc code=start

struct ArrayHasher {
    size_t operator()(const std::array<int, 26>& arr) const {
        size_t hash = 0;

        for (int val : arr) {
            hash ^= std::hash<int>{}(val) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }

        return hash;
    }
};

class Solution {
public:
    std::vector<std::vector<std:: string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::array<int, 26>, std::vector<std::string>, ArrayHasher> group;

        for (auto& str : strs) {
            group[build_anagram_key(str)].emplace_back(std::move(str));
        }

        std::vector<std::vector<std:: string>> result;
        result.reserve(group.size());

        for (auto& [key, value] : group) {
            result.emplace_back(std::move(value));
        }

        return result;
    }

    std::array<int, 26> build_anagram_key(const std::string& str) {
        std::array<int, 26> key = {0};

        for (const char c : str) {
            ++key[c - 'a'];
        }
        
        return key;
    }
};
// @lc code=end

