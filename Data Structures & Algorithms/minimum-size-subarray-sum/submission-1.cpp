class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = n + 1;
        int l = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum >= target) {
                ans = min(r - l, ans);
                sum -= nums[l];
                l++;
            }
        }
        return ans == n + 1 ? 0 : ans + 1;

    }
};