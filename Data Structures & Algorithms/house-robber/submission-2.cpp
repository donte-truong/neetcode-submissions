class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int temp = rob2;
            rob2 = max(nums[i] + rob1, rob2);
            rob1 = temp;
        }

        return max(rob1, rob2);
    }
};
