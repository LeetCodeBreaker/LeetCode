# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def mergeTwoLists(self, l1, l2):
        first = l1
        second = l2
        answer = []
        while(first and second):
            if(first.val < second.val):
                answer.append(first.val)
                first = first.next
            else:
                answer.append(second.val)
                second = second.next
        while(first):
            answer.append(first.val)
            first = first.next
        while(second):
            answer.append(second.val)
            second = second.next
        nodelist = []
        for num in answer:
            nodelist.append(ListNode(num))
        for i in range(len(nodelist)-1):
            nodelist[i].next = nodelist[i+1]
        if(nodelist):
            return nodelist[0]
        else:
            return []
