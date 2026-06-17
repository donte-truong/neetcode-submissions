# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def compare(self, tree1, tree2):
            print("!" if not tree1 else tree1.val, "!" if not tree2 else tree2.val)
            if tree1 is None or tree2 is None:
                return tree1 == tree2
            if tree1.val != tree2.val:
                return False
            
            left = self.compare(tree1.left, tree2.left)
            right = self.compare(tree1.right, tree2.right)

            return left and right

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root is None: 
            return False
        if root.val == subRoot.val and self.compare(root, subRoot): 
            return True
        
        left = self.isSubtree(root.left, subRoot)
        right = self.isSubtree(root.right, subRoot)

        return left or right