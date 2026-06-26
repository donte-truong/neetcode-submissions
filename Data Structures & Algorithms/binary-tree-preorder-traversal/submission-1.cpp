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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> calls;

        TreeNode* curr = root;
        while (curr || !calls.empty()) {
            if (!curr) {
                curr = calls.top();
                calls.pop();
                curr = curr->right;
            } else {
                ans.push_back(curr->val);
                calls.push(curr);
                curr = curr->left;
            }
        }

        return ans;
    }
};