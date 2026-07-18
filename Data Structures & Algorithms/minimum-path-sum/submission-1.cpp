class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<int> dp(COLS);
        int sum = 0;
        for (int i = COLS - 1; i >= 0; --i) {
            sum += grid[ROWS - 1][i];
            dp[i] = sum;
        }

        for (int r = ROWS - 2; r >= 0; --r) {
            vector<int> nextDp = grid[r];
            nextDp[COLS - 1] = dp[COLS - 1] + grid[r][COLS - 1];
            for (int c = COLS - 2; c >= 0; --c) {
                nextDp[c] = min(dp[c], nextDp[c + 1]) + grid[r][c];
            }
            swap(nextDp, dp);
        }

        return dp[0];
    }
};