class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int max_diff = 0;
        int n = nums.size();
        for(int i = 0; i< n;i++){
            int next = (i != n-1)? i+1 : 0;
            if(max_diff < abs(nums[i] - nums[next])) max_diff = abs(nums[i] - nums[next]); 
        }
        return max_diff;
    }
};