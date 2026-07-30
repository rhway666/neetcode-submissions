class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // a ^ a = 0
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            ans ^= i;
            ans ^= nums[i]; 
        }
        return ans;
        // [3,0,1]
        // init ans = 3;
        // i = 0; ans = 0
        // i = 1; ans = 1
        // i = 2; ans = 2
    }
};
