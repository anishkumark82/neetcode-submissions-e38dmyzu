# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:
            return []
        out = []
        Q = deque()
        Q.append(root)

        while Q:
            qSize = len(Q)
            level = []
            for i in range(0, qSize):
                cur = Q.popleft()
                level.append(cur.val)
                if cur.left:
                    Q.append(cur.left)
                if cur.right:
                    Q.append(cur.right)
            out.append(level)
        return out
