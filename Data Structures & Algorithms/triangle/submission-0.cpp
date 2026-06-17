class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int r = triangle.size() - 2; r >= 0; r--) {
            for (int i = 0; i < triangle[r].size(); i++) {
                triangle[r][i] += min(triangle[r+1][i], triangle[r+1][i+1]);
            }
        }
        return triangle[0][0];
    }
};