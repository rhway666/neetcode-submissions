class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        max_profit = 0
        if len(prices) <= 1:
            return 0;
        for i in range(1,len(prices)):
            max_profit = max(prices[i] - buy, max_profit)
            if prices[i] < buy:
                buy = prices[i]
        
        return max_profit
            