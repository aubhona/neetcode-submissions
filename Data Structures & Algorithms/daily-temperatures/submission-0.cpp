class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();

        std::vector<int> result(n, 0);
        std::vector<int> stack;

        stack.reserve(n);
        
        for (int i = 0; i < n; ++i) {
            int temp = temperatures[i];

            while (!stack.empty() && temperatures[stack.back()] < temp) {
                int idx = stack.back();

                result[idx] = i - idx;
                stack.pop_back();
            }
            
            stack.push_back(i);
        }
        
        return result;
    }
};
