class Solution {
private:
    bool backtrack(vector<int>& nums, int i, vector<int>& subsets, int target) {
        if (i == nums.size()) return true;

        for (int j = 0; j < subsets.size(); j++) {
            if (subsets[j] + nums[i] > target) continue;

            subsets[j] += nums[i];
            if (backtrack(nums, i + 1, subsets, target)) return true;
            subsets[j] -= nums[i];

            if (subsets[j] == 0) break;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;

        sort(nums.begin(), nums.end(), greater<>());
        
        vector<int> subsets(k, 0);
        return backtrack(nums, 0, subsets, total / k);

    }
};