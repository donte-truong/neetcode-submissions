class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(piles.size() + 1, vector<int>(piles.size() + 1, 0));

        for (int i = n - 2; i >= 0; --i) {
            piles[i] += piles[i + 1];
        }

        for (int l = n - 1; l >= 0; --l) {
            for (int M = 1; M <= n; ++M) {
                for (int i = 1; i <= 2 * M && l + i <= n; ++i) {
                    dp[l][M] = max(dp[l][M], piles[l] - dp[l + i][max(M, i)]);
                }
            }
        }

        return dp[0][1];
    }
};