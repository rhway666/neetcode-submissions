/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* curr) {
        if (!curr) return 0;
        int left_height = curr->left ? dfs(curr->left) : 0;
        int right_height = curr->right ? dfs(curr->right) : 0;
        ans = max(ans, left_height + right_height);
        return 1 + max(left_height, right_height);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return ans;
    }
};
