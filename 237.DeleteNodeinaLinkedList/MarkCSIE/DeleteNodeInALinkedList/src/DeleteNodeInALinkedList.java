
class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class DeleteNodeInALinkedList {

    public static void main(String[] args) {
        DeleteNodeInALinkedList test = new DeleteNodeInALinkedList();
        
        ListNode testCase1 = new ListNode(1);
        testCase1.next = new ListNode(2);
        testCase1.next.next = new ListNode(3);
        testCase1.next.next.next = new ListNode(4);
        test.deleteNode(testCase1.next.next);
    }

    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }

}
