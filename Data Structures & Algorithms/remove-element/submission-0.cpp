class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int numPointer = 0, valPointer = 0;

        while (numPointer < nums.size() && valPointer < nums.size()) {
            int num = nums[numPointer];
            if (nums[valPointer] != val) {
                valPointer++;
            } else if (numPointer < valPointer) {
                numPointer = valPointer;
            } else if (nums[numPointer] == val) {
                numPointer++;
            } else {
                swap(nums[numPointer], nums[valPointer]);
                valPointer++;
            }
        }

        return valPointer;
    }
};