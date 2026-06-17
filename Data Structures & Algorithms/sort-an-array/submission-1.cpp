#include <thread>

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeArray(span<int>(nums));
        
        return nums;
    }

private:
    static void mergeArray(span<int> nums) {
        if (nums.size() <= 1) return;

        size_t mid = nums.size() / 2;

        if (nums.size() > 100) {
            thread left(&mergeArray, nums.subspan(0, mid));
            thread right(&mergeArray, nums.subspan(mid));
            left.join();
            right.join();
        } else {
            mergeArray(nums.subspan(0, mid));
            mergeArray(nums.subspan(mid));
        }

        vector<int> mergedArray(nums.size());

        int l = 0; int r = mid;
        for (int i = 0; i < nums.size(); i++) {
            if (l < mid && (r >= nums.size() || nums[l] <= nums[r])) {
                mergedArray[i] = nums[l];
                l++;
            } else {
                mergedArray[i] = nums[r];
                r++;
            }
        }

        for (int j = 0; j < nums.size(); j++) {
            nums[j] = mergedArray[j];
        }
    }
};