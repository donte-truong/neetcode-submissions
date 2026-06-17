class Solution {
public:
    int trap(vector<int>& height) {

        int leftMax = 0;
        vector<int> walls(height.size(), 0);

        for (int i = 0; i < height.size() - 1; ++i) {
            leftMax = max(height[i], leftMax);
            walls[i+1] = leftMax;
        }

        int rightMax = 0;
        int ans = 0;

        for (int j = height.size() - 1; j >= 0; --j) {
            ans += max(min(walls[j], rightMax) - height[j], 0);
            rightMax = max(height[j], rightMax);
        }

        return ans;
    }
};
