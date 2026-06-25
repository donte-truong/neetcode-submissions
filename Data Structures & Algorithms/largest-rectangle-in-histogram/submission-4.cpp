class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        int maxArea = 0;
        vector<pair<int, int>> boxes;

        for (int i = 0; i < n; i++) {
            
            int height = heights[i];
            int start = i;
            
            while (!boxes.empty() && height < boxes.back().first) {
                pair<int, int> prev = boxes.back();
                boxes.pop_back();

                start = prev.second;
                maxArea = max(maxArea, (i - prev.second) * prev.first);
            }

            boxes.push_back({height, start});

        }

        for (auto box : boxes) {
            maxArea = max(maxArea, (n - box.second) * box.first);
        }

        return maxArea;

    }
};
