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
    void dfs(TreeNode* curr) {
        if (!curr) return;
        if (!curr->left && !curr->right) return;
        TreeNode* temp = curr->right;
        curr->right = curr->left;
        curr->left = temp;
        dfs(curr->left);
        dfs(curr->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        dfs(root);
        return root;
    }
};
