
class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class SwapNodesinPairs {

    public static void main(String[] args) {
        ListNode testCase1 = new ListNode(5);
        testCase1.next = new ListNode(4);
        testCase1.next.next = new ListNode(3);
        testCase1.next.next.next = new ListNode(2);
        testCase1.next.next.next.next = new ListNode(1);

        SwapNodesinPairs test = new SwapNodesinPairs();
        ListNode answer = test.swapPairs(testCase1);
        while (true) {
            System.out.print(answer.val);
            if (answer.next == null) {
                break;
            } else {
                answer = answer.next;
            }
            System.out.print("->");
        }
        System.out.println();
    }

    public ListNode swapPairs(ListNode head) {
        ListNode currentNode = head;
        ListNode lastNode = null;
        ListNode tempNode = null;
        if (currentNode != null && currentNode.next != null) {
            head = currentNode.next;
        }
        while (currentNode != null && currentNode.next != null) {
            tempNode = currentNode.next;
            currentNode.next = currentNode.next.next;
            tempNode.next = currentNode;
            if (lastNode != null) {
                lastNode.next = tempNode;
            }
            lastNode = currentNode;
            currentNode = currentNode.next;
        }
        return head;
    }
}
