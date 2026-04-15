/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */


#include <vector>

// @lc code=start
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::vector<int> stack;
        stack.reserve(heights.size());

        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!stack.empty() && heights[i] < heights[stack.back()]) {
                const auto height = heights[stack.back()];

                stack.pop_back();

                const auto left = stack.empty() ? -1 : stack.back();

                max_area = std::max(height * (i - left - 1), max_area);
            }

            stack.push_back(i);
        }

        while (!stack.empty()) {
            const auto height = heights[stack.back()];

            stack.pop_back();

            const auto left = stack.empty() ? -1 : stack.back();

            max_area = std::max(height * ((int)heights.size() - left - 1), max_area);
        }

        return max_area;
    }
};
// @lc code=end

