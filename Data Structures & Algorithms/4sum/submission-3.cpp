class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        kSum(nums, 4, 0, (long long) target);

        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> quad;

    vector<vector<int>> kSum(vector<int>& nums, int k, int i, long long target) {
        int n = nums.size();

        if (k == 2) {

            int l = i, r = n - 1;

            while (l < r) {
                long long sum = (long long) nums[l] + nums[r];
                if (sum == target) {
                    quad.push_back(nums[l]);
                    quad.push_back(nums[r]);
                    ans.push_back(quad);
                    quad.pop_back();
                    quad.pop_back();
                    do {
                        l++;
                    } while (l < r && nums[l] == nums[l - 1]);
                    do {
                        r--;
                    } while (l < r && nums[r] == nums[r + 1]);
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }

            return ans;

        }

        for (int j = i; j < n; j++) {
            if (j > i && nums[j] == nums[j - 1]) continue;

            quad.push_back(nums[j]);
            kSum(nums, k - 1, j + 1, target - nums[j]);
            quad.pop_back();
        }

        return ans;

    }
};