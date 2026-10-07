# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # we use bfs, i.e. queue, and add things as lists??

        if not root:
            return []

        q = deque()
        res = []
        q.append(root)

        while len(q):
            acc = []
            for i in range(len(q)):
                curr = q.popleft()
                acc.append(curr.val)
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            res.append(acc)
        return res