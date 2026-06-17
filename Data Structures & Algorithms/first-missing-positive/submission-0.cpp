class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int& num : nums) {
            if (num < 0) num = 0;
        }

        for (int num : nums) {
            int val = abs(num);
            if (1 <= val && val <= nums.size()) {
                if (nums[val - 1] > 0) nums[val - 1] *= -1;
                if (nums[val - 1] == 0) nums[val - 1] = -1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) return i + 1; 
        }

        return nums.size() + 1;
    }
};