class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixes;

        int sums = 0;

        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixes[currSum] += 1;
            currSum += nums[i];
            sums += prefixes[currSum - k];
        }
        
        return sums;
    }
};