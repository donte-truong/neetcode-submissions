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
private:
    bool dfs(TreeNode* node, int target) {
        if (!node) return false;

        bool left = dfs(node->left, target);
        bool right = dfs(node->right, target);

        if (left) node->left = nullptr;
        if (right) node->right = nullptr;

        return (node->val == target && !node->left && !node->right) ? true : false;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        bool isLeaf = dfs(root, target);

        return isLeaf ? nullptr : root;

    }
};