class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int pivot = partition(nums, low, high);

        quickSort(nums, low, pivot - 1);
        quickSort(nums, pivot + 1, high);
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];

        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[j], nums[i]);
            }
        }

        swap(nums[i + 1], nums[high]);
        return i + 1;
    }
};