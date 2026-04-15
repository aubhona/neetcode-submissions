class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        for (const char c : s) {
            s_map[c]++;
        }

        for (const char c : t) {
            t_map[c]++;
        }

        return s_map == t_map;
    }
};
