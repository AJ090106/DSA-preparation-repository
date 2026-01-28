class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // 1. Find the maximum value in the grid
        int maxVal = 0;
        for (auto &row : grid) {
            for (int val : row) {
                maxVal = max(maxVal, val);
            }
        }

        const int INF = 1e9;

        // dp[i][j] = min cost to reach (n-1, m-1) from (i, j)
        vector<vector<int>> dp(n, vector<int>(m, INF));

        // temp[v] = min cost starting from ANY cell with value v
        vector<int> temp(maxVal + 1, INF);
        vector<int> best(maxVal + 1, INF);

        // Base case: target cell
        temp[grid[n - 1][m - 1]] = 0;
        dp[n - 1][m - 1] = 0;

        // -------- INITIALIZATION (k = 0, only walking) --------
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) continue;

                int down = (i + 1 < n) ? dp[i + 1][j] + grid[i + 1][j] : INF;
                int right = (j + 1 < m) ? dp[i][j + 1] + grid[i][j + 1] : INF;

                dp[i][j] = min(down, right);

                if (dp[i][j] != INF) {
                    temp[grid[i][j]] = min(temp[grid[i][j]], dp[i][j]);
                }
            }
        }

        // -------- TELEPORT LAYERS (k > 0) --------
        for (int step = 0; step < k; step++) {

            // 1. Prefix minimum
            best[0] = temp[0];
            for (int v = 1; v <= maxVal; v++) {
                best[v] = min(best[v - 1], temp[v]);
            }

            // 2. Relax DP using teleport
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (i == n - 1 && j == m - 1) continue;

                    int down = (i + 1 < n) ? dp[i + 1][j] + grid[i + 1][j] : INF;
                    int right = (j + 1 < m) ? dp[i][j + 1] + grid[i][j + 1] : INF;
                    int walkCost = min(down, right);

                    // Teleport option
                    int teleportCost = best[grid[i][j]];

                    dp[i][j] = min(walkCost, teleportCost);

                    // Update temp for next iteration
                    if (dp[i][j] != INF) {
                        temp[grid[i][j]] = min(temp[grid[i][j]], dp[i][j]);
                    }
                }
            }
        }

        return dp[0][0];
    }
};