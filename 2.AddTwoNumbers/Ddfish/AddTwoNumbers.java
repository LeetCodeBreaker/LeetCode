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
               if(now.val >=10){
                  now.val -= 10;
                  now.next = new ListNode(1);
                }else{
                    if(b.next == null){
                        break;
                    }else{
                        now.next = new ListNode(0);
                        
                    }
                    
                }
              
              
          }else if(b == null){
              now.val += a.val;
               if(now.val >=10){
                  now.val -= 10;
                  now.next = new ListNode(1);
                }else{
                    if(a.next == null){
                        break;
                    }else{
                        now.next = new ListNode(0);
                    }
                }
          }else{
              now.val = now.val + a.val + b.val;
              if(now.val >=10){
                  now.val -= 10;
                  now.next = new ListNode(1);
             }else{
                  if(a.next == null && b.next == null){
                    break;
                  }else{
                      now.next = new ListNode(0);
                  }
             }
          }
          now = now.next;
          if(a != null){
            a = a.next;
          }
          if(b != null){
            b = b.next;
          }
        }
        return answer;
        
    }
}
