
class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class RemoveDuplicatesFromSortedList {

    public static void main(String[] args) {
        RemoveDuplicatesFromSortedList test = new RemoveDuplicatesFromSortedList();

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
        while (currNode != null) {
            if (currNode.next != null && currNode.val == currNode.next.val) {
                currNode.next = currNode.next.next;
            } else {
                currNode = currNode.next;
            }
        }
        return head;
    }

}
