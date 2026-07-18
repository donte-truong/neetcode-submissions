class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int, int>> oranges;

        int num = 0;
        for (int i{0}; i < ROWS; ++i) {
            for (int j{0}; j< COLS; ++j) {
                if (grid[i][j] == 2) {
                    oranges.push({i, j});
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 1) {
                    ++num;
                } 
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int time = 0;
        while (!oranges.empty() && num != 0) {
            int level = oranges.size();
            cout << level << ' ';
            for (int k{0}; k < level; ++k) {
                auto [r, c] = oranges.front();
                oranges.pop();

                for (int i{0}; i < 4; ++i) {
                    auto [x, y] = directions[i];
                    int adjR = r + x;
                    int adjC = c + y;
                    if (adjR < 0 || adjC < 0 || adjR >= ROWS || adjC >= COLS || grid[adjR][adjC] == 0)
                        continue;

                    --num;
                    grid[adjR][adjC] = 0;
                    oranges.push({adjR, adjC});
                }
            }
            time += 1;
        }
        return num == 0 ? time : -1;
    }
};
