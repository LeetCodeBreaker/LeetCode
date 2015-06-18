public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0;
        ListNode answer = new ListNode(0);
        ListNode now = answer;
        ListNode a = l1;
        ListNode b = l2;
     
       while(true){
          
          if(a == null && b == null){
              break;
          }else if(a == null){
              now.val += b.val;
              if(now.val < 10 && b.next != null){
                 
                 now.next = new ListNode(0);
              }
            
          }else if(b == null){
              now.val += a.val;
               if(now.val < 10 && a.next != null){
                
                   now.next = new ListNode(0);
               }
             
          }else{
             now.val = now.val + a.val + b.val;
              if(now.val < 10 && (a.next != null || b.next != null)){
                
                   now.next = new ListNode(0);
               }
 
          }
          if(now.val >=10){
                  now.val -= 10;
                  now.next = new ListNode(1);
          }
          
          now = now.next;
          try{
            a = a.next;
          }catch(java.lang.NullPointerException e){
          }
          try{
            b = b.next;
          }catch(java.lang.NullPointerException e){
          }
          
        }
        
        
        return answer;
        
    }
}
