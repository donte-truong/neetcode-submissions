class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;

        for (int m = 0; m < k; m++) {
            vector<int> nextDp(n + 1, INT_MAX);
            for (int i = n - 1; i >= 0; i--) {
                int currSum = 0;
                for (int j = i; j < n - m; j++) {
                    currSum += nums[j];
                    nextDp[i] = min(nextDp[i], max(currSum, dp[j + 1]));
                }
            }
            swap(nextDp, dp);
        }

        return dp[0];

    }
};