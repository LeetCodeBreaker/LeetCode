
class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class MergeTwoSortedLists {

    public static void main(String[] args) {
        ListNode testCase1 = new ListNode(1);
        testCase1.next = new ListNode(1);
        testCase1.next.next = new ListNode(1);
        testCase1.next.next.next = new ListNode(2);
        testCase1.next.next.next.next = new ListNode(3);

        ListNode testCase2 = new ListNode(1);
        testCase2.next = new ListNode(1);
        testCase2.next.next = new ListNode(1);
        testCase2.next.next.next = new ListNode(2);
        testCase2.next.next.next.next = new ListNode(3);
        
        MergeTwoSortedLists test = new MergeTwoSortedLists();
        ListNode testAnswer1 = test.mergeTwoLists(testCase1, testCase2);
        while (testAnswer1 != null) {
            System.out.print(testAnswer1.val);
            System.out.print(" ");
            testAnswer1 = testAnswer1.next;
        }
        System.out.println();
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        } else if (l2 == null) {
            return l1;
        }

        ListNode head = null;
        ListNode currNode = head;
        while (true) {
            if (l1 == null) {
                currNode.next = l2;
                break;
            }
            if (l2 == null) {
                currNode.next = l1;
                break;
            }

            ListNode targetNode;
            if (l1.val <= l2.val) {
                targetNode = l1;
                l1 = l1.next;
            } else {
                targetNode = l2;
                l2 = l2.next;
            }

            if (currNode == null) {
                head = targetNode;
                currNode = targetNode;
            } else {
                currNode.next = targetNode;
                currNode = currNode.next;
            }
        }
        return head;
    }
}
