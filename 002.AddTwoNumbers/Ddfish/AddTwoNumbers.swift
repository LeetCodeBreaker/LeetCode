/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
    
          let ans = ListNode(0)
        
        var now = ans
        var ln1 = l1
        var ln2 = l2
        
        while(true){
        
            now.val +=  ( (ln1 != nil) ? ln1!.val : 0) + ( (ln2 != nil) ? ln2!.val : 0)
            
            ln1 = ln1?.next
            ln2 = ln2?.next
            
            if now.val >= 10 {
                now.val -= 10
                now.next = ListNode(1)
            }else{
                if(ln1 != nil || ln2 != nil){
                    now.next = ListNode(0)
                }else{
                    break
                }
            }
            
            now = now.next!
            
        }
    
        return ans


        
        
    }
}
