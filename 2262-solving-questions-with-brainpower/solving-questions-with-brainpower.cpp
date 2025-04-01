class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int rows = questions.size();
        vector<long long> dp(rows, 0);

        // Start from the last question
        dp[rows - 1] = questions[rows - 1][0];

        for (int i = rows - 2; i >= 0; i--) {
            long long skip = dp[i + 1];  // If we skip this question
            long long take = questions[i][0];  // If we take this question

            // Ensure we don't go out of bounds
            if (i + 1 + questions[i][1] < rows) {
                take += dp[i + 1 + questions[i][1]];
            }

            dp[i] = std::max(skip, take);
        }

        return dp[0];  // Maximum points from the first question
    }
};
