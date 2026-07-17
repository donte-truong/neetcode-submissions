class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int inc = 1, dec = 1, maxSize = 1;

        for (int i{1}; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < 0) {
                inc = dec + 1;
                dec = 1;
            } else if (diff > 0) {
                dec = inc + 1;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }

            maxSize = max({inc, dec, maxSize});
        }

        return maxSize;
    }
};