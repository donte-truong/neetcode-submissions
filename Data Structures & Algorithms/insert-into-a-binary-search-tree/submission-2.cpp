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
    void dfs(TreeNode* node, int val) {
        if (!node->left && val <= node->val) {
            TreeNode* next = new TreeNode(val);
            node->left = next;
            return;
        }

        if (!node->right && val >= node->val) {
            TreeNode* next = new TreeNode(val);
            node->right = next;
            return;
        }

        if (node->val >= val)
            dfs(node->left, val);
        else
            dfs(node->right, val);
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        dfs(root, val);
        return root;
    }
};