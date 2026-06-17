# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        def dfs(root):
            if root is None:
                return False
                    
            left = dfs(root.left)
            right = dfs(root.right)

            if left and right:
                return root
            elif left or right:
                if type(left) == TreeNode or type(right) == TreeNode:
                    return left if left else right
                return True if root.val != p.val and root.val != q.val else root
            elif root.val == p.val or root.val == q.val:
                return True
            else:
                return False
        
        return dfs(root)