class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        map<int, int> mymap;
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (mymap.find(t) != mymap.end()) {
                solution.push_back(mymap[t]);
                solution.push_back(i);
                break;
            }
            mymap[nums[i]] = i;
        }
        return solution;
    }
};