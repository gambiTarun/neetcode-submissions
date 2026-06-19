# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # slow is in middle now
        # reverse second half of the list
        node = slow.next
        prev = None
        slow.next = None
        while node:
            tmp = node.next
            node.next = prev
            prev = node
            node = tmp

        slow = prev
        node = head
        while slow:
            tmp1 = node.next
            tmp2 = slow.next
            node.next = slow
            slow.next = tmp1
            node = tmp1
            slow = tmp2
