class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long goal = (long long) target - nums[i] - nums[j];
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    if (nums[l] + nums[r] == goal) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do {
                            l++;
                        } while (l < r && nums[l] == nums[l - 1]);
                        do {
                            r--;
                        } while (l < r && nums[r] == nums[r + 1]);
                    } else if (nums[l] + nums[r] < goal) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};