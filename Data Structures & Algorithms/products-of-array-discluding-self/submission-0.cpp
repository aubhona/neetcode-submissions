class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result(nums.size() + 1, 1);

        for (long long i = nums.size() - 1; i >= 0; --i) {
            result[i] = result[i + 1] * nums[i];
        }

        auto prefixProd = 1;

        for (auto i = 0ull; i < nums.size(); ++i)
        {
            result[i] = prefixProd * result[i + 1];
            prefixProd *= nums[i];
        }

        result.pop_back();

        return result;
    }
};