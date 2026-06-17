# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, currMax):
            if not node:
                return 0

            isLarger = False
            if node.val >= currMax:
                isLarger = True
            
            left = dfs(node.left, node.val if isLarger else currMax)
            right = dfs(node.right, node.val if isLarger else currMax)

            return 1+left+right if isLarger else left+right

        return dfs(root, root.val)
