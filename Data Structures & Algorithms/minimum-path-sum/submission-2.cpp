class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<int> dp(COLS);

        int total = 0;
        for (int i{COLS - 1}; i >= 0; --i) {
            total += grid[ROWS - 1][i];
            dp[i] = total;
        }

        for (int r = ROWS - 2; r >= 0; --r) {
            vector<int> nextDp(COLS);
            nextDp[COLS - 1] = dp[COLS - 1] + grid[r][COLS - 1];
            for (int c = COLS - 2; c >= 0; --c) {
                nextDp[c] = min(nextDp[c + 1], dp[c]) + grid[r][c];
            }
            swap(nextDp, dp);
        }

        return dp[0];
    }
};