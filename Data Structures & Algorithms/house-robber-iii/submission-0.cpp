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

    pair<int, int> getMax(TreeNode* node) {
        if (!node) return {0, 0};

        pair<int, int> leftMax = getMax(node->left);
        pair<int, int> rightMax = getMax(node->right);

        return {
            node->val + leftMax.second + rightMax.second,
            max(leftMax.first, leftMax.second) + max(rightMax.first, rightMax.second)
        };
    }

public:
    int rob(TreeNode* root) {
        
        pair<int, int> maxVal = getMax(root);

        return max(maxVal.first, maxVal.second);

    }
};