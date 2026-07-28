class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 2; i >= 0; --i)
            piles[i] += piles[i + 1];

        for (int l = n - 1; l >= 0; --l) {
            for (int M = 1; M <= n; ++M) {
                bool maxCap = false;
                if (maxCap) {
                    dp[l][M] = dp[l][M + 1];
                    continue;
                }
                for (int r = 1; r <= 2 * M; ++r) {
                    if (l + r > n) {
                        maxCap = true;
                        break;
                    }
                    dp[l][M] = max(dp[l][M], piles[l] - dp[l + r][max(r, M)]);
                }
            }
        }

        return dp[0][1];
    }
};