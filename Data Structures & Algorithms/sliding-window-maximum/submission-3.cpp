class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        result.reserve(nums.size() - k + 1);

        std::multiset<int> sorted_window;

        for (size_t i = 0; i < k; i++) {
            sorted_window.insert(nums[i]);
        }

        auto left = 0;
        auto right = k ;

        result.push_back(*sorted_window.rbegin());

        while (right < nums.size()) {
            sorted_window.erase(sorted_window.find(nums[left++]));
            sorted_window.insert(nums[right++]);

            result.push_back(*sorted_window.rbegin());
        }

        return result;
    }
};