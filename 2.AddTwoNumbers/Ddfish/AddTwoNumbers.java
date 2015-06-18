public class AddTwoNumbers {
   public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0;
        ListNode answer = new ListNode(0);
        ListNode now = answer;
        ListNode a = l1;
        ListNode b = l2;
     
     do{
           if(a != null){
               now.val += a.val;
               a = a.next;
           }
           if(b != null){
               now.val += b.val;
               b = b.next;
           }
           if(now.val >=10){
               now.val -=10;
               now.next = new ListNode(1);
           }else{
               if(a != null || b != null){
                   now.next = new ListNode(0);
               }
           }
           now = now.next;
           
        }while(a != null || b != null);
        return answer;
        
}
