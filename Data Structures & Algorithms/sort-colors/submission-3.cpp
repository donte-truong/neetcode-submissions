class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0;
        int l = nums.size() - 1;

        int i = 0;
        while (i <= l) {
            if (nums[i] == 0) {
                swap(nums[i], nums[r]);
                r++;
            }
            
            if (nums[i] == 2) {
                swap(nums[i], nums[l]);
                l--;
                continue;
            } 
            
            i++;
        }
    }
};