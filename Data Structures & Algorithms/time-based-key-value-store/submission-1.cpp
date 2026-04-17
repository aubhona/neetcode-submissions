class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> time_map_;
    
public:
    TimeMap() {}
    
    void set(std::string key, std::string value, int timestamp) {
        time_map_[key].push_back(std::make_pair(timestamp, value));
    }
    
    std::string get(std::string key, int timestamp) {
        auto& history = time_map_[key];
        int left = 0;
        int right = history.size() - 1;
        while (left <= right) {
            auto mid = left + (right - left) / 2;
            
            if (history[mid].first == timestamp) {
                return history[mid].second;
            } else if (history[mid].first < timestamp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right >= 0 ? history[right].second : "";
    }
};
