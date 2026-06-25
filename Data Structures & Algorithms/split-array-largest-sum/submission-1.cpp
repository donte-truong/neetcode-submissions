class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> prefix(n);

        int curr = 0;
        int l = INT_MAX, r = 0;

        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            prefix[i] = curr;
            l = min(l, nums[i]);
            r = curr;
        }

        while (l <= r) {

            int m = l + (r - l) / 2;

            if (checkSubarrays(prefix, k, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }

        }

        return l;

    }

private:
    bool checkSubarrays(vector<int>& prefix, int k, int val) {
        
        int prev = 0;
        int l = 0;

        for (int i = 0; i < k; i++) {

            int r = prefix.size();

            while (l < r) {
                int m = l + (r - l) / 2;

                if (prefix[m] - prev > val) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }

            if (l == 0 || l >= prefix.size()) break;

            prev = prefix[l - 1];

            if (prefix[l] - prev > val) return false;

        }

        return l >= prefix.size();

    }
};