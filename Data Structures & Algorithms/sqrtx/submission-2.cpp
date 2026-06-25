class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;

        int l = 0, r = x / 2;

        while (l <= r) {

            int m = l + (r - l) / 2;
            long long square = (long long) m * m;

            if (square == x) {
                return m;
            } else if (square < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }

        }

        return l - 1;
    }
};