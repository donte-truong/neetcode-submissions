class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        deque<int> dp(3, 0);

        for (int i{n - 1}; i >= 0; --i) {
            int maxDiff = INT_MIN;
            int currSum = 0;
            for (int k{0}; k < 3 && i + k < n; ++k) {
                currSum += stoneValue[i + k];
                maxDiff = max(maxDiff, currSum - dp[k]);
            }
            dp.pop_back();
            dp.push_front(maxDiff);
            for (int& diff : dp)
                cout << diff << ' ';
            cout << endl;
        }

        if (dp.front() > 0) {
            return "Alice";
        } else if (dp.front() < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};