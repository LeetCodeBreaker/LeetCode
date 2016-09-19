#include <iostream>

//  Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
public:

    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* odd_current = head;
        ListNode* odd_prev = nullptr;
        ListNode* even_head = head->next;
        ListNode* even_current = head->next;

        ListNode* current = head->next;
        while (current != nullptr) {
            odd_current->next = current->next;
            odd_prev = odd_current;
            odd_current = odd_current->next;

            current = current->next;
            if (current == nullptr) {
                break;
            }

            even_current->next = current->next;
            even_current = even_current->next;

            current = current->next;
        }

        if (odd_current == nullptr) {
            odd_prev->next = even_head;
        } else {
            odd_current->next = even_head;
        }

        return head;
    }
};

int main() {
    Solution solution;
    ListNode* test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(3);
    test->next->next->next = new ListNode(4);
    test->next->next->next->next = new ListNode(5);
    ListNode* answer = solution.oddEvenList(test);

    while (answer != nullptr) {
        std::cout << answer->val << " ";
        answer = answer->next;
    }
    std::cout << std::endl;

    delete test->next->next->next->next;
    delete test->next->next->next;
    delete test->next->next;
    delete test->next;
    delete test;

    return 0;
}

