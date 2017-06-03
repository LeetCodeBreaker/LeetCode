
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class Solution {
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        
        let tempNode = ListNode(0)
        tempNode.next =  head
        
        var first  : ListNode? = tempNode
        var second : ListNode? = tempNode
        
        var count = 0
        while first != nil {
            first = first?.next
            if(count > n){
                second = second?.next
            }
            count += 1
        }
        second?.next = second?.next?.next
        
        
        return tempNode.next
    }
}
