class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
         if(head == None or head.next==None):
            return None
         slow = head.next
         fast = head.next.next
         cycle = False
         while(slow != None and fast != None and fast.next!= None):
             if slow is fast:
                 cycle = True
                 break
             slow = slow.next
             fast = fast.next.next
         if(not cycle):
             return None
         else:
            fast = head
            while(slow != None and fast != None and fast.next!= None):
                 if slow is fast:
                     return slow
                 slow = slow.next
                 fast = fast.next
