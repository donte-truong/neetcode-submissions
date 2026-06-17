# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        stack = [root]

        while stack and root:
            res.append(stack[-1].val)
            level = []
            for i in range(len(stack)):
                if stack[i].left:
                    level.append(stack[i].left)
                if stack[i].right:
                    level.append(stack[i].right)
            stack = level
        return res
