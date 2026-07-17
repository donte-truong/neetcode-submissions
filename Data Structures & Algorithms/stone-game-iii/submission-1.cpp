class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        for (int i{n - 1}; i >= 0; --i) {
            int maxDiff = INT_MIN;
            int currSum = 0;
            for (int k{0}; k < 3 && i + k < n; ++k) {
                currSum += stoneValue[i + k];
                maxDiff = max(maxDiff, currSum - dp[i + k + 1]);
            }
            dp[i] = maxDiff;
        }

        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};