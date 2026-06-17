class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }

private:
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int pivot = partition(nums, low, high);

        quickSort(nums, low, pivot);
        quickSort(nums, pivot + 1, high);
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low + (high - low) / 2];

        int i = low - 1;
        int j = high + 1;

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