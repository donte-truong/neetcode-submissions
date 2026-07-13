class Solution {

private:
    vector<vector<int>> combinations;

    void backtrack(int n, int k, int i, vector<int>& combination) {
        if (combination.size() == k) {
            combinations.push_back(combination);
            return;
        }

        if (i == n + 1) return;

        vector<int> include(combination);
        include.push_back(i);
        backtrack(n, k, i + 1, include);
        backtrack(n, k, i + 1, combination);
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> empty = {};
        backtrack(n, k, 1, empty);
        return combinations;
    }
};