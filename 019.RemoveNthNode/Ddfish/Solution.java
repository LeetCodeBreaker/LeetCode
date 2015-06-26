{
  
  
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        ListNode[] node = new ListNode[2];
        node[0] = head;
        node = inner(node ,n);
        return node[0];
    }
        
    
    private ListNode[] inner(ListNode[] head,int n){
        
        if(head[1] == null){
            head[1] = new ListNode(0);
        }
        if(head[0].next == null){
            
            if(n == 1 ){
                head[0] = null;
            }
            head[1].val = 1;
            return head;
        }
        ListNode[] next = new ListNode[]{head[0].next , head[1].next};
        next = inner(next,n);
        
        head[1].val = next[1].val+1;
        head[0].next = next[0];
        
        if(head[1].val == n){
            
            head[0] = head[0].next;
        }
        return head;
    }
}
