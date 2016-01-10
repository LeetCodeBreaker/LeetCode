#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
public:

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prev_node = nullptr;
        ListNode* curr_node = head;
        for (int i = 0; i < m - 1; i++) {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        ListNode* first_prev_node = prev_node;
        ListNode* first_node = curr_node;

        ListNode* temp_node = curr_node->next;
        for (int i = 0; i < n - m; i++) {
            prev_node = curr_node;
            curr_node = temp_node;

            temp_node = curr_node->next;
            curr_node->next = prev_node;
        }
        if (first_prev_node) {
            first_prev_node->next = curr_node;
        } else {
            head = curr_node;
        }
        first_node->next = temp_node;

        return head;
    }
};

int main() {
    Solution solution;

    ListNode *test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(3);
    test->next->next->next = new ListNode(4);
    test->next->next->next->next = new ListNode(5);

    ListNode *answer = solution.reverseBetween(test, 2, 4);
    while (answer) {
        std::cout << answer->val << std::endl;
        answer = answer->next;
    }

    delete test->next->next->next->next;
    delete test->next->next->next;
    delete test->next->next;
    delete test->next;
    delete test;

    return 0;
}

