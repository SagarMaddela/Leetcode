class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int rows = questions.size();
        vector<long long> dp(rows, 0);
        dp[rows - 1] = questions[rows - 1][0];

        for (int i = rows - 2; i >= 0; i--) {
            long long skip = dp[i + 1];  
            long long take = questions[i][0];  

            if (i + 1 + questions[i][1] < rows) {
                take += dp[i + 1 + questions[i][1]];
            }

            dp[i] = std::max(skip, take);
        }

        return dp[0]; 
    }
};
