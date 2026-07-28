class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<int> dp(piles.size(), 0);

        for (int l = piles.size() - 1; l >= 0; --l) {
            vector<int> nextDp = dp;
            nextDp[l] = piles[l];
            for (int r = l + 1; r < piles.size(); ++r) {
                nextDp[r] = max(piles[r] - nextDp[r - 1], piles[l] - dp[r]);
            }
            swap(nextDp, dp);
        }
        return dp[piles.size() - 1] > 0;
    }
};