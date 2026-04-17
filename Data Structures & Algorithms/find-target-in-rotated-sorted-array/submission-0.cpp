class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            auto mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[left] == target)
            {
                return left;
            }

            if (nums[right] == target)
            {
                return right;
            }

            if (target > nums[mid]) {
                if (nums[mid] > nums[left]) {
                    left = mid + 1;
                } else {
                    if (target > nums[left] )
                    {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            } else {
                if (nums[mid] < nums[right]) {
                    right = mid - 1;
                } else {
                    if (target < nums[right] )
                    {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }

        return -1;
    }
};
