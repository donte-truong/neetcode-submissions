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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        while (curr && curr->val != key) {
            prev = curr;
            if (key < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (!curr)
            return root;

        if (!curr->left || !curr->right) {
            TreeNode* child = curr->left ? curr->left : curr->right;
            if (!prev) return child;
            if (prev->left == curr)
                prev->left = child;
            else
                prev->right = child;
            delete curr;
        } else {
            TreeNode* before = curr;
            TreeNode* next = curr->left;
            while (next->right) {
                before = next;
                next = next->right;
            }
            if (before != curr) {
                before->right = next->left;
                next->left = curr->left;
            }
            next->right = curr->right;
            if (!prev) return next;
            if (prev->left == curr)
                prev->left = next;
            else
                prev->right = next;
            delete curr;
        }

        return root;
    }
};