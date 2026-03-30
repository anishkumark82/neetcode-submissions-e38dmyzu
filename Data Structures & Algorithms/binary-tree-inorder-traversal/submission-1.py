# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _inorder(self, root: Optional[TreeNode], out: List[int]) -> None:
        if root == None:
            return 
        
        self._inorder(root.left, out)
        out.append(root.val)
        self._inorder(root.right, out)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        out = []
        self._inorder(root, out)
        return out