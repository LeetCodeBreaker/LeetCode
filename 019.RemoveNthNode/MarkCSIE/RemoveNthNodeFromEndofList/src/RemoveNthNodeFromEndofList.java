
import java.util.ArrayList;
import java.util.List;

class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class RemoveNthNodeFromEndofList {

    public static void main(String[] args) {
        ListNode testCase1 = new ListNode(2);
        testCase1.next = new ListNode(4);
        testCase1.next.next = new ListNode(3);

        RemoveNthNodeFromEndofList test = new RemoveNthNodeFromEndofList();
        ListNode testAnswer = test.removeNthFromEnd(testCase1, 1);
        while (true) {
            System.out.println(testAnswer.val);
            if (testAnswer.next == null) {
                break;
            } else {
                testAnswer = testAnswer.next;
            }
        }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        List<ListNode> nodes = new ArrayList<>();
        nodes.add(head);
        ListNode lastNode = head;
        while (lastNode.next != null) {
            lastNode = lastNode.next;
            nodes.add(lastNode);
        }
        int listLength = nodes.size();
        ListNode previousNode = null;
        if (listLength - n - 1 != -1) {
            previousNode = nodes.get(listLength - n - 1);
        }
        ListNode nextNode = nodes.get(listLength - n).next;
        if (previousNode == null) {
            return nextNode;
        }
        previousNode.next = nextNode;
        return head;
    }

}
