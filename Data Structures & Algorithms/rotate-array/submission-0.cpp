class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        int count = 0;

        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int nextIdx = (current + k) % n;
                int temp = nums[nextIdx];
                nums[nextIdx] = prev;
                prev = temp;
                current = nextIdx;
                count++;
            } while (current != start);
        }
    }

};