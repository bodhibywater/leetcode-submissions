# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:

        length = 0
        cur = head

        while cur:
            cur = cur.next
            length += 1
        
        if (length - n == 0):
            return head.next;
        
        # now to remove (length - n) node
        cur = head

        for i in range(length - n - 1):
            cur = cur.next

        cur.next = cur.next.next

        return head
        
