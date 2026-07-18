class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ROWS = obstacleGrid.size(), COLS = obstacleGrid[0].size();
        vector<int> dp(COLS, 0);
        for (int i = COLS - 1; i >= 0; --i) {
            if (obstacleGrid[ROWS - 1][i] == 0) {
                dp[i] = 1;
            } else {
                break;
            }
        }

        for (int i = ROWS - 2; i >= 0; --i) {
            vector<int> nextDp(COLS, 0);
            nextDp[COLS - 1] = obstacleGrid[i][COLS - 1] == 0 ? dp[COLS - 1] : 0;
            for (int j = COLS - 2; j >= 0; --j) {
                if (obstacleGrid[i][j] == 0)
                    nextDp[j] = nextDp[j + 1] + dp[j];
            }
            swap(nextDp, dp);
        }

        return dp[0];
    }
};