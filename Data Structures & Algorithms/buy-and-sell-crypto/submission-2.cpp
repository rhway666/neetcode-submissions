class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxP = 0;

        // [4,5,6,3,8,9,3]
        //        l r
        while (r < prices.size()) {
            maxP = max(prices[r] - prices[l], maxP);
            if (prices[r] < prices[l]) {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};
