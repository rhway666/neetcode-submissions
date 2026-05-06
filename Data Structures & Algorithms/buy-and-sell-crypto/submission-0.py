class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minn = prices[0]
        sub = 0
        n = len(prices)
        for i in range(1, n):
            if prices[i] - minn > sub:
                sub = prices[i] - minn
            if prices[i] < minn:
                minn = prices[i]
        
        return sub
