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
    bool check_same(TreeNode* curr_p, TreeNode* curr_q) {
        if (!curr_p && !curr_q) return true;
        if (!curr_p || !curr_q) return false;
        if (curr_p->val != curr_q->val) return false;
        
        return check_same(curr_p->left, curr_q->left) && check_same(curr_p->right, curr_q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check_same(p, q);
    }
};
