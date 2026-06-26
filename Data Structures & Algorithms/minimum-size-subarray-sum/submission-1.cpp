class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int length = INT_MAX;

        int currSum = 0;

        for (int r = 0; r < nums.size(); r++) {

            currSum += nums[r];

            while (currSum >= target) {
                length = min(length, r - l + 1);
                currSum -= nums[l++];
            }

        }

        return length == INT_MAX ? 0 : length;
    }
};