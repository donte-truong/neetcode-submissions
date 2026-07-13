class Solution {

public:
    int subsetXORSum(vector<int>& nums) {
        int ors = 0;

        for (int num : nums) {
            ors |= num;
        }

        return ors << (nums.size() - 1);
    }
};