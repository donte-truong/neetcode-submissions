class Solution {
    public int maxArea(int[] heights) {
        int l = 0;
        int r = heights.length-1;
        int maxWater = 0;
        while (l < r) {
            maxWater = Math.max((r-l)*Math.min(heights[l], heights[r]), maxWater);
            if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }
        return maxWater;
    }
}
