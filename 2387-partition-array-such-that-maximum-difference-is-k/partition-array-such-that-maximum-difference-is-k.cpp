class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        int n = nums.size();
        int curr = 0,count = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] > nums[curr] + k){
                count++;
                curr = i;
            }
        }
        return count + 1;
    }
};

