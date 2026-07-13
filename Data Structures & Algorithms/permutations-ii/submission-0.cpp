class Solution {

private:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[i]) continue;

            swap(nums[i], nums[j]);
            backtrack(nums, i + 1);
        }

        for (int j = nums.size() - 1; j > i; j--) {
            swap(nums[j], nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        backtrack(nums, 0);

        return ans;

    }
};