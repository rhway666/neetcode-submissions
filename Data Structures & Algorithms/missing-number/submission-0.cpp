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
    }
};
