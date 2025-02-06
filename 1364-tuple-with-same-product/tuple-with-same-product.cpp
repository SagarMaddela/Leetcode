class Solution {
public:
    int tupleSameProduct(std::vector<int>& nums) {
        std::unordered_map<int, int> store;
        int size = nums.size();
        int total_count = 0;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int product = nums[i] * nums[j];
                store[product]++;  
            }
        }

        for (const auto &iter : store) {
            int count = iter.second;
            if (count > 1) {
                total_count += (count * (count - 1)) / 2; 
            }
        }

        return total_count * 8;  
    }
};

