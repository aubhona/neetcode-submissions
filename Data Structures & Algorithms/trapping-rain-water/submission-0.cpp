class Solution {
public:
    int trap(std::vector<int>& height) {
        auto left = 0;
        auto right = height.size() - 1;
        auto left_max = height[left];
        auto right_max = height[right];
        auto result = 0;

        while (left < right) {
            if (left_max <= right_max)
            {
                result += left_max - height[left];
                ++left;
                left_max = std::max(left_max, height[left]);
            } else {
                result += right_max - height[right];
                --right;
                right_max = std::max(right_max, height[right]);
            }
        }

        return result;
    }
};
