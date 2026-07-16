class Solution {
private:
    unordered_map<int, int> memo;

    int dfs(int target) {
        if (memo.contains(target))
            return memo[target];

        int res = target;
        for (int i{1}; i * i <= target; ++i) {
            res = min(res, 1 + dfs(target - i * i));
        }

        return memo[target] = res;
    }

public:
    int numSquares(int n) {
        memo[0] = 0;
        return dfs(n);    
    }
};