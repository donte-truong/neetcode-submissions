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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->right) {
                ans.push_back(curr->val);
                curr = curr->left;
                continue;
            }

            TreeNode* post = curr->right;
            while (post->left && post->left != curr) {
                post = post->left;
            }

            if (post->left == curr) {
                post->left = nullptr;
                curr = curr->left;
            } else {
                post->left = curr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};