
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        
        guard let l1 = l1 else {
            return l2
        }
        guard let l2 = l2 else {
            return l1
        }
        
        var answer : ListNode?
        
        if l1.val < l2.val {
            answer = ListNode(l1.val)
            answer?.next = mergeTwoLists(l1.next, l2)
        }else{
            answer = ListNode(l2.val)
            answer?.next = mergeTwoLists(l1, l2.next)
        }
        
        return answer
    }
    
}
