class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        cars.reserve(position.size());
        
        for (int i = 0; i < position.size(); i++) {
            cars.emplace_back(position[i], speed[i]);
        }
        
        std::sort(cars.begin(), cars.end());
        
        int result = 1;
        double last_time = (target - cars.back().first) / (double)cars.back().second;
        
        for (int i = cars.size() - 2; i >= 0; --i) {
            double current_time = (target - cars[i].first) / (double)cars[i].second;
            if (current_time > last_time) {
                ++result;
                last_time = current_time;
            }
        }
        
        return result;
    }
};
