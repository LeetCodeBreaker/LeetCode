
class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class RemoveDuplicatesFromSortedListII {

    public static void main(String[] args) {
        RemoveDuplicatesFromSortedListII test = new RemoveDuplicatesFromSortedListII();

        ListNode testCase1 = new ListNode(1);
        testCase1.next = new ListNode(1);
        testCase1.next.next = new ListNode(2);
        testCase1.next.next.next = new ListNode(3);
        testCase1.next.next.next.next = new ListNode(3);
        ListNode testAnswer = test.deleteDuplicates(testCase1);

        while (testAnswer != null) {
            System.out.println(testAnswer.val);
            testAnswer = testAnswer.next;
        }
    }

    public ListNode deleteDuplicates(ListNode head) {
        ListNode currNode = head;
        ListNode prevNode = null;
        while (currNode != null) {
            if (currNode.next != null && currNode.val == currNode.next.val) {
                ListNode duplicateNode = currNode.next;
                while (duplicateNode != null && duplicateNode.val == currNode.val) {
                    duplicateNode = duplicateNode.next;
                }
                if (prevNode == null) {
                    head = duplicateNode;
                } else {
                    prevNode.next = duplicateNode;
                }
                currNode = duplicateNode;
            } else {
                prevNode = currNode;
                currNode = currNode.next;
            }
        }
        return head;
    }
}
