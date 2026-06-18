class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        priority_queue<pair<int, vector<int>>> frontier;
        frontier.push({0, {0, 0}});

        vector<vector<int>> costMap(ROWS, vector<int>(COLS, INT_MAX));
        costMap[0][0] = 0;

        while (!frontier.empty()) {
            pair<int, vector<int>> node = frontier.top();
            frontier.pop();

            int cost = -node.first;
            vector<int> pos = node.second;

            int r = pos[0], c = pos[1];

            if (r == ROWS - 1 && c == COLS - 1) return cost;

            for (const auto& dir : dirs) {
                int adjR = r + dir[0], adjC = c + dir[1];

                if (min(adjR, adjC) < 0 || adjR >= ROWS || adjC >= COLS) 
                    continue;

                int adjCost = abs(heights[adjR][adjC] - heights[r][c]);
                int newCost = max(cost, adjCost);

                if (newCost < costMap[adjR][adjC]) {
                    costMap[adjR][adjC] = newCost;
                    frontier.push({-newCost, {adjR, adjC}});
                }
            }
        }

        return -1;
    }
};