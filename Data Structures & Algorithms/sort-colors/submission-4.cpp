class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = 0;
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            nums[i] = 2;
            if (num < 2) {
                nums[j++] = 1;
            }
            if (num < 1) {
                nums[k++] = 0;
            }
        }
    }
};