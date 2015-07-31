# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def swapPairs(self, head):
        if(not head or not head.next):
            return head
        first = head
        second = head.next
        _second = second
        while(first and second):
            third = second.next
            tmp = first
            second.next = tmp
            if(not third or not third.next):
                first.next = third
                break
            else:
                first.next = third.next
                first = third
                second = third.next
        return _second
