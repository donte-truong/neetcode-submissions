# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum = float("-infinity")

        def dfs(root):
            nonlocal maxSum

            if root == None:
                return 0
            
            right = max(0, dfs(root.right))
            left = max(0, dfs(root.left))

            maxSum = max(right + left + root.val, maxSum)

            return max(right, left)+root.val

        dfs(root)

        return maxSum