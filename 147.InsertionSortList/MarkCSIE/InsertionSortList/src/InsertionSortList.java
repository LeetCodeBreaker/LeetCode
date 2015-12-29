
class ListNode {

    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class InsertionSortList {

    public static void main(String[] args) {
        InsertionSortList test = new InsertionSortList();

        ListNode testCase1 = new ListNode(5);
        testCase1.next = new ListNode(4);
        testCase1.next.next = new ListNode(3);
        testCase1.next.next.next = new ListNode(2);
        testCase1.next.next.next.next = new ListNode(1);
        ListNode answer = test.insertionSortList(testCase1);
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

    public ListNode insertionSortList(ListNode head) {
        if (head != null) {
            ListNode currentNode = head.next;
            head.next = null;
            while (currentNode != null) {
                ListNode tempNode = head;
                ListNode prevNode = null;
                ListNode nextCurrentNode = currentNode.next;

                while (tempNode != null) {
                    if (currentNode.val <= tempNode.val) {
                        if (prevNode != null) {
                            prevNode.next = currentNode;
                        } else { // insert to the first position
                            head = currentNode;
                        }
                        currentNode.next = tempNode;
                        break;
                    }
                    prevNode = tempNode;
                    tempNode = tempNode.next;
                }

                if (tempNode == null) { // insert to the last position
                    prevNode.next = currentNode;
                    currentNode.next = null;
                }

                currentNode = nextCurrentNode;
            }
        }

        return head;
    }
}
