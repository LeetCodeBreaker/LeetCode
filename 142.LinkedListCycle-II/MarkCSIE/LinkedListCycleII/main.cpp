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

    ListNode *detectCycle(ListNode *head) {
        // t = X + nY + K
        // 2t = X + mY+ K
        // => X+K  =  (m-2n)Y 

        ListNode *first = head;
        ListNode *second = head;

        while (first != nullptr && second != nullptr) {
            first = first->next;
            second = second->next;
            if (second != nullptr) {
                second = second->next;
            }
            if (first == second) {
                break;
            }
        }

        if (second == nullptr) {
            return nullptr;
        }

        first = head;
        while (first != second) {
            first = first->next;
            second = second->next;
        }

        return second;
    }
};

int main() {
    Solution solution;
    ListNode *test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(3);
    test->next->next->next = new ListNode(4);
    test->next->next->next->next = new ListNode(5);
    test->next->next->next->next->next = test->next->next;

    ListNode *answer = solution.detectCycle(test);
    std::cout << answer->val << std::endl;

    delete test->next->next->next->next;
    delete test->next->next->next;
    delete test->next->next;
    delete test->next;
    delete test;

    return 0;
}

