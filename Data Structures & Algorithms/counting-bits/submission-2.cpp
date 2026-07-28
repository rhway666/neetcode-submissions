class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        vector<int> rc(n + 1);
        // n = 11001 n-1 = 11000 n-2 = 10111
        // n-1 & n-2 = 01000
        // idx [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]
        // cnt [0,1,1,2,1,2,2,3,1,2,2 ,3 ,2 ,3 ,3, 4, 1 ,2]
        // 會重複 idx/2 的時候的循環
        // ans[i] = ans[i]
        // 0:0
        // 1:1
        // 2~3: 1+ dp[i - 2^1]
        // 4~7: 1+dp[i - 2^2]
        // 8~15: 1 + dp[i - 2^3]
        ans.push_back(0);
        int offset = 1;
        for (int i = 1; i <= n; i++) {
            if (offset * 2 == i){
                offset = i;
            }
            ans.push_back(ans[i - offset] + 1);
        }
        return ans;
    }
};
