class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        bitset<30001> dp;
        dp[0] = 1;

        for (int& stone : stones) {
            dp |= dp << stone;
        }

        for (int i = sum / 2; i >= 0; --i) {
            if (dp[i] > 0)
                return sum - 2 * i;
        }

        return -1;
    }
};