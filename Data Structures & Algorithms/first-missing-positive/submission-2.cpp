class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (1 <= nums[i] && nums[i] <= nums.size() && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != j + 1) return j + 1;
        }
        return nums.size() + 1;
    }
};