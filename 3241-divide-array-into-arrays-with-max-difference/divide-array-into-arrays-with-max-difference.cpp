class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        int i = 0,n = nums.size();
        std::vector<vector<int>> result;
        while(i < n){
            if(nums[i+2] - nums[i] <= k){
                //std::cout << "Group is valid (max - min <= " << k << "): ";
               // std::cout << "[" << nums[i] << ", " << nums[i + 1] << ", " << nums[i + 2] << "]" << std::endl;
                result.push_back({nums[i], nums[i+1], nums[i+2]});
                i += 3;
            } else {
                std::vector<vector<int>> empty;
                return empty;
            }
        }

        return result;
    }
};