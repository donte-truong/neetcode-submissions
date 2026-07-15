class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j <= grid[i].size(); ++j) {
                int above = j > 0 ? grid[i][j - 1] : 0;
                int below = j < grid[i].size() ? grid[i][j] : 0;
                if (above + below == 1) ++perimeter;
            }
        }

        for (int i = 0; i <= grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int left = i > 0 ? grid[i - 1][j] : 0;
                int right = i < grid.size() ? grid[i][j] : 0;
                if (left + right == 1) ++perimeter;
            }
        }

        return perimeter;
    }
};