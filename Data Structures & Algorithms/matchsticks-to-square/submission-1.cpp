class Solution {
private:
    bool backtrack(vector<int>& matchsticks, int i, vector<int>& sides, int length) {
        if (i == matchsticks.size()) return true;

        for (int j = 0; j < sides.size(); j++) {
            if (sides[j] + matchsticks[i] > length) continue;

            sides[j] += matchsticks[i];
            if (backtrack(matchsticks, i + 1, sides, length)) return true;
            sides[j] -= matchsticks[i];

            if (sides[j] == 0) break;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;

        sort(matchsticks.begin(), matchsticks.end(), greater<>());

        vector<int> sides(4, 0);
        return backtrack(matchsticks, 0, sides, sum / 4);
    }
};