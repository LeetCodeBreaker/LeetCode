class Solution:
    def hasCycle(self, head):
            slow = head
            fast = head
            while(slow != None and fast.next != None and fast.next.next !=None):
                slow = slow.next
                fast = fast.next.next
                if(slow.val == fast.val):
                    return True   
            return False
