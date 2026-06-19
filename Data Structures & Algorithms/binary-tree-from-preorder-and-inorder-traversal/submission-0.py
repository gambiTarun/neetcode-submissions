# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        inordermap = {v: i for i, v in enumerate(inorder)}
        return build(0, 0, len(preorder)-1, preorder, inordermap)
    
def build(pid, l, r, preorder, inordermap):
    if l>r or pid>=len(preorder):
        return None
    n = TreeNode(preorder[pid])
    print("deb", preorder[pid])
    mid = inordermap[preorder[pid]]
    pid += 1
    n.left = build(pid, l, mid-1, preorder, inordermap)
    n.right = build(pid + mid - l, mid+1, r, preorder, inordermap)
    return n