class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globMin = nums[0], globMax = nums[0];

        int currMin = 0, currMax = 0;
        int total = 0;

        for (int& num : nums) {
            currMin = min(currMin + num, num);
            currMax = max(currMax + num, num);

            globMin = min(currMin, globMin);
            globMax = max(currMax, globMax);

            total += num;
        }

        return globMax > 0 ? max(globMax, total - globMin) : globMax;
    }
};