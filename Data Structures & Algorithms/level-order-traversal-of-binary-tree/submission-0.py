# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        res = [[root.val]]
        stack = [root]
        while stack:
            level = []
            for i in range(len(stack)):
                if not stack[i]:
                    continue
                level.append(stack[i].left)
                level.append(stack[i].right)
            stack = level
            values = [node.val for node in level if node]
            if values: res.append(values)
        return res