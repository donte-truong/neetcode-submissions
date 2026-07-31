class Solution {
public:
    int uniquePaths(int m, int n) {
        int top = m + n - 2;
        int bottom = min(m, n) - 1;

        long long result = 1;
        for (int i = 1; i <= bottom; ++i) {
            result *= top - i + 1;
            result /= i;
        }
        return result;
    }
};
