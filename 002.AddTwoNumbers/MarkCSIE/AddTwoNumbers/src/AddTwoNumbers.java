
class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class AddTwoNumbers {

    public static void main(String[] args) {
        ListNode testCase1 = new ListNode(2);
        testCase1.next = new ListNode(4);
        testCase1.next.next = new ListNode(3);

        ListNode testCase2 = new ListNode(5);
        testCase2.next = new ListNode(6);
        testCase2.next.next = new ListNode(4);

        AddTwoNumbers test = new AddTwoNumbers();
        ListNode answerListNode1 = test.addTwoNumbers(testCase1, testCase2);

        while (true) {
            System.out.println(answerListNode1.val);
            if (answerListNode1.next == null) {
                break;
            } else {
                answerListNode1 = answerListNode1.next;
            }
        }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode head = new ListNode(0);
        ListNode current = head;
        while (true) {
            int num1 = 0;
            int num2 = 0;
            if (l1 != null) {
                num1 = l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                num2 = l2.val;
                l2 = l2.next;
            }
            int sum = num1 + num2 + carry;
            current.val = sum;
            if (sum > 9) {
                current.val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            if (l1 != null || l2 != null) {
                ListNode nextNode = new ListNode(0);
                current.next = nextNode;
                current = nextNode;
            } else {
                break;
            }
        }
        if (carry == 1) {
            ListNode last = new ListNode(1);
            current.next = last;
        }
        return head;
    }
}
