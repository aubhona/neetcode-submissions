class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        auto right_max = prices[prices.size() - 1];
        auto max_profit = 0;

        for (int i = prices.size() - 1; i >= 0; --i) {
            const auto& price = prices[i];

            max_profit = std::max(max_profit, right_max - price);
            right_max = std::max(price, right_max);
        }

        return max_profit;
    }
};
