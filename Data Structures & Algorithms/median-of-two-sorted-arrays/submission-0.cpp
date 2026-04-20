/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        if (nums1.empty())
        {
            return nums2.size() % 2 == 0 ? (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1]) / 2.0 : nums2[nums2.size() / 2];
        }

        int left = 0, right = nums1.size();
        int max_left, min_right;

        auto total_left = (nums1.size() + nums2.size() + 1) / 2;

        while (left <= right) {
            auto mid1 = left + (right - left) / 2;
            auto mid2 = total_left - mid1;

            if (mid1 > 0 && nums1[mid1 - 1] > nums2[mid2])
            {
                right = mid1 - 1;
                continue;
            }

            if (mid1 != nums1.size() && nums1[mid1] < nums2[mid2 - 1])
            {
                left = mid1 + 1;
                continue;
            }
            
            if (mid1 == 0)
            {
                max_left = nums2[mid2 - 1];
            }
            else if (mid2 == 0)
            {
                max_left = nums1[mid1 - 1];
            }
            else
            {
                max_left = std::max(nums1[mid1 - 1], nums2[mid2 - 1]);
            }

            if (mid1 == nums1.size())
            {
                min_right = nums2[mid2];
            }
            else if (mid2 == nums2.size())
            {
                min_right = nums1[mid1];
            }
            else
            {
                min_right = std::min(nums1[mid1], nums2[mid2]);
            }

            if ((nums1.size() + nums2.size()) % 2 == 0)
            {
                return (max_left + min_right) / 2.0;
            }
            else
            {
                return max_left;
            }
        }

        return 0.0;
    }
};
// @lc code=end
