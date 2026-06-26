class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> counts;

        for (int i = 0; i < nums.size(); i++) {

            if (counts.contains(nums[i])) return true;

            counts.insert(nums[i]);

            if (i - k >= 0) {
                counts.erase(nums[i - k]);
            }

        }

        return false;
    }
};