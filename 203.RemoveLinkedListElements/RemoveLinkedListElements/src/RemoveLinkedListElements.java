
class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class RemoveLinkedListElements {

    public static void main(String[] args) {
        RemoveLinkedListElements test = new RemoveLinkedListElements();

        ListNode testCase1 = new ListNode(1);
        testCase1.next = new ListNode(2);
        testCase1.next.next = new ListNode(6);
        testCase1.next.next.next = new ListNode(3);
        testCase1.next.next.next.next = new ListNode(4);
        testCase1.next.next.next.next.next = new ListNode(5);
        testCase1.next.next.next.next.next.next = new ListNode(6);

        ListNode testAnswer = test.removeElements(testCase1, 1);
        while (testAnswer != null) {
            System.out.println(testAnswer.val);
            testAnswer = testAnswer.next;
        }

    }

    public ListNode removeElements(ListNode head, int val) {
        ListNode prevNode = null;
        ListNode currNode = head;
        while (currNode != null) {
            if (currNode.val == val) {
                if (prevNode == null) {
                    head = head.next;
                } else {
                    prevNode.next = currNode.next;
                }
            } else {
                prevNode = currNode;
            }
            currNode = currNode.next;
        }
        return head;
    }
}
