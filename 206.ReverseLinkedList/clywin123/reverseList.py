class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        if(not head):
            return None
        if(not head.next):
            return head
        tmp = head.next
        newhead = self.reverseList(tmp)
        tmp.next = head
        head.next = None
        return newhead
        
