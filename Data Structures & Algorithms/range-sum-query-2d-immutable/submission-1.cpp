class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        grid = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));

        int sum = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                sum = matrix[i][j] + getSum(i - 1, j) + getSum(i, j - 1) - getSum(i - 1, j - 1);
                grid[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) - getSum(row2, col1 - 1) - getSum(row1 - 1, col2) + getSum(row1 - 1, col1 - 1);
    }

private:
    vector<vector<int>> grid;

    int getSum(int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[r].size()) return 0;

        return grid[r][c];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */