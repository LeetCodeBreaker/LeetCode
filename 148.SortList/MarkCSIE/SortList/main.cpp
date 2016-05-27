#include <iostream>

// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
public:

    ListNode* sortList(ListNode* head) {
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return sortListWithLength(head, length);
    }

private:

    ListNode* sortListWithLength(ListNode* head, const int &length) {
        if (length <= 1) {
            return head;
        }

        ListNode* current = head;
        for (int i = 0; i < length / 2 - 1; i++) {
            current = current->next;
        }
        ListNode* second = current->next;
        current->next = nullptr;

        ListNode* sorted_first = sortListWithLength(head, length / 2);
        ListNode* sorted_second = sortListWithLength(second, length - length / 2);

        return mergeTwoLists(sorted_first, sorted_second);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }

        ListNode* head = nullptr;
        ListNode* currNode = head;
        while (true) {
            ListNode* targetNode;
            if (l1->val <= l2->val) {
                targetNode = l1;
                l1 = l1->next;
            } else {
                targetNode = l2;
                l2 = l2->next;
            }

            if (currNode == nullptr) {
                head = targetNode;
                currNode = targetNode;
            } else {
                currNode->next = targetNode;
                currNode = currNode->next;
            }

            if (l1 == nullptr) {
                currNode->next = l2;
                break;
            }
            if (l2 == nullptr) {
                currNode->next = l1;
                break;
            }
        }
        return head;
    }
};

int main() {
    ListNode *testCase = new ListNode(4);
    testCase->next = new ListNode(3);
    testCase->next->next = new ListNode(5);
    testCase->next->next->next = new ListNode(2);
    testCase->next->next->next->next = new ListNode(1);

    Solution solution;
    ListNode *answer = solution.sortList(testCase);
    while (answer) {
        std::cout << answer->val << std::endl;
        answer = answer->next;
    }

    delete testCase->next->next->next->next;
    delete testCase->next->next->next;
    delete testCase->next->next;
    delete testCase->next;
    delete testCase;

    return 0;
}

