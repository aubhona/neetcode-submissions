/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */


 // @lc code=start

 #include <cstddef>
 
class MinStack {
private:
    int* data_;
    int* min_;
    std::size_t size_;
    std::size_t capacity_;
    std::size_t min_size_;
    std::size_t min_capacity_;

public:
    MinStack() : data_(nullptr), min_(nullptr), size_(0), capacity_(10), min_size_(0), min_capacity_(10) {
        data_ = new int[capacity_];
        min_ = new int[min_capacity_];
    }

    ~MinStack() {
        delete[] data_;
        delete[] min_;
    }
    
    void push(int val) {
        if (size_ == capacity_)
        {
            capacity_ *= 2;

            int* new_data = new int[capacity_];

            for (std::size_t i = 0; i < size_; ++i)
            {
                new_data[i] = data_[i];
            }

            delete[] data_;

            data_ = new_data;
        }

        data_[size_++] = val;

        if (min_size_ == 0 || min_[min_size_ - 1] >= val)
        {
            if (min_size_ == min_capacity_)
            {
                min_capacity_ *= 2;

                int* new_min = new int[min_capacity_];

                for (std::size_t i = 0; i < min_size_; ++i)
                {
                    new_min[i] = min_[i];
                }

                delete[] min_;

                min_ = new_min;
            }

            min_[min_size_++] = val;
        }
    }
    
    void pop() {
        if (data_[size_ - 1] == min_[min_size_ - 1])
        {
            min_[--min_size_] = 0;
        }

        data_[--size_] = 0;
    }
    
    int top() {
        return data_[size_ - 1];
    }
    
    int getMin() {
        return min_[min_size_ - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
