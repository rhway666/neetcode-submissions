class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr_sub;
        backtrack(nums, 0, curr_sub, ans);
        return ans;
    }
private:
    void backtrack(const vector<int>& nums, int l, vector<int>& curr_sub, vector<vector<int>>& ans) {
        if (l >= nums.size()) {
            ans.push_back(curr_sub);
            return;
        }
        curr_sub.push_back(nums[l]);
        backtrack(nums, l + 1, curr_sub, ans);
        curr_sub.pop_back();
        backtrack(nums, l + 1, curr_sub, ans);
    }
};
