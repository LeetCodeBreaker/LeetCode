# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def deleteDuplicates(self, head):
        if(not head):
            return head
        tmp = [head.val]
        first = head
        while(first.next!=None):
            if(first.next.val in tmp):
                first.next = first.next.next
            else:
                tmp.append(first.next.val)
                first = first.next
        return head
