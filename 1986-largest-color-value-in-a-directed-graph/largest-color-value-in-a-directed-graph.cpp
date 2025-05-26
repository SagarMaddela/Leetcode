class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        
        // Add nodes with 0 indegree
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int visitedCount = 0;
        int result = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            visitedCount++;
            int colorIndex = colors[u] - 'a';
            dp[u][colorIndex]++;

            result = max(result, dp[u][colorIndex]);

            for (int v : graph[u]) {
                for (int c = 0; c < 26; ++c) {
                    dp[v][c] = max(dp[v][c], dp[u][c]);
                }
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If all nodes not visited, there is a cycle
        return visitedCount == n ? result : -1;
    }
};
