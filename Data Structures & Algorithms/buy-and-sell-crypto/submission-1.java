class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int purchaseTime = 0;
        int sellTime = 0;
        while (sellTime < prices.length) {
            int currentProfit = prices[sellTime] - prices[purchaseTime];
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
            if (currentProfit < 0) {
                purchaseTime = sellTime;
            }
            sellTime++;
        }
        return maxProfit;
    }
}
