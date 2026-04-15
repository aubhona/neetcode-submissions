class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> nums_set;
        nums_set.reserve(nums.size());

        for (const int num : nums) {
            if (nums_set.count(num) > 0) {
                return true;
            }

            nums_set.insert(num);
        }

        return false;
    }
};