class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int ans = 0;

        while (l <= r) {
            if (leftMax <= rightMax) {
                ans += max(min(leftMax, rightMax) - height[l], 0);
                leftMax = max(leftMax, height[l++]);
            } else {
                ans += max(min(leftMax, rightMax) - height[r], 0);
                rightMax = max(rightMax, height[r--]);
            }
        }
        
        return ans;
    }
};
