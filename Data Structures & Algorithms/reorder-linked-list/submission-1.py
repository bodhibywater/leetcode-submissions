# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow = fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        l1 = head                    # input list
        l2 = self.reverseList(slow)  # reversed second half of input list

        while l1.next and l2.next:
            temp = l1.next
            temp2 = l2.next

            l1.next = l2
            l2.next = temp

            l1 = temp
            l2 = temp2

    def reverseList(self, head: Optional[ListNode]) -> None:
        cur, prev = head, None

        while cur:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
        
        return prev