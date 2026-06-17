class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size());
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int low, int high) {
        if (low + 1 >= high) return;

        int pivot = partition(nums, low, high);

        quickSort(nums, low, pivot + 1);
        quickSort(nums, pivot + 1, high);
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low + (high - 1 - low) / 2];

        int i = low - 1;
        int j = high;
        while (true) {
            do {
                i++;
            } while (nums[i] < pivot);

            do {
                j--;
            } while (nums[j] > pivot);

            if (i >= j) return j;

            swap(nums[i], nums[j]);
        }
    }
};