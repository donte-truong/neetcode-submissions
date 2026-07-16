class Solution {
    unordered_map<int, int> memo;

public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        memo[0] = 1;
        return dfs(nums, target);
    }

private:
    int dfs(vector<int>& nums, int target) {
        if (memo.contains(target)) {
            return memo[target];
        }

        int res = 0;
        for (int& num : nums) {
            if (num > target) break;
            res += dfs(nums, target - num);
        }
        memo[target] = res;
        return res;
    }
};