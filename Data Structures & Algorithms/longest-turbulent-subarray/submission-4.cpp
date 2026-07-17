class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0;
        int comp = 0;
        int maxSize = 1;

        for (int r{1}; r < arr.size(); ++r) {
            int diff = arr[r] - arr[r - 1];
            diff = (diff > 0) - (diff < 0);

            if (diff == 0) {
                l = r;
            } else if (comp != 0 && diff == comp) {
                l = r - 1;
            }

            comp = diff;
            maxSize = max(maxSize, r - l + 1);
        }

        return maxSize;
    }
};