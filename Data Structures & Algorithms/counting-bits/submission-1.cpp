class Solution {
public:
    vector<int> countBits(int n) {
        // 14 -> 8 + 4 + 2 
        vector<int> ans(n + 1);
        int bits = sizeof(int) * 8;
        for (int num = 1; num <= n; num++) {
            for (int i = 0; i < bits; i++) {
                if (num & (1 << i)) {
                    ans[num]++;
                }
            }
        }
        return ans;
    }
};
