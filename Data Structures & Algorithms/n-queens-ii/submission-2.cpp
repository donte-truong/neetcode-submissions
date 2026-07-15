class Solution {
private:
    vector<bool> cols;
    vector<bool> diag1;
    vector<bool> diag2;

    int solutions = 0;

    void backtrack(int row) {
        if (row == cols.size()) {
            solutions++;
            return;
        }

        for (int col = 0; col < cols.size(); col++) {
            int d1 = row + col;
            int d2 = col - row + cols.size() - 1;

            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            cols[col] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1);
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }

public:
    int totalNQueens(int n) {
        cols.assign(n, false);
        diag1.assign(n * 2 - 1, false);
        diag2.assign(n * 2 - 1, false);

        backtrack(0);

        return solutions;
    }
};