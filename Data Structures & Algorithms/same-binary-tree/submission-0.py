# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, tree1: Optional[TreeNode], tree2: Optional[TreeNode]) -> bool:
        if tree1 is None or tree2 is None:
            return tree1 == tree2
        elif tree1.val != tree2.val:
            return False
        left, right = self.isSameTree(tree1.left, tree2.left), self.isSameTree(tree1.right, tree2.right)
        return True if left and right else False