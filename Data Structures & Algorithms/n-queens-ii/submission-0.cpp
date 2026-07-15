class Solution {
private:
    vector<bool> cols;
    vector<bool> diag1;
    vector<bool> diag2;

    int solutions = 0;

    void backtrack(int row) {
        if (row == cols.size()) {
            solutions += 1;
            return;
        }

        for (int col = 0; col < cols.size(); col++) {
            int d1 = row + col;
            int d2 = row - col + cols.size();

            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            cols[col] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1);
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }


public:
    int totalNQueens(int n) {
        cols.assign(n, false);
        diag1.assign(2 * n, false);
        diag2.assign(2 * n, false);

        backtrack(0);

        return solutions;
    }
};