#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;

        //        if (head) {
        //            ListNode* new_head = nullptr;
        //            ListNode* tail = recursive(head, &new_head);
        //            tail->next = nullptr;
        //            return new_head;
        //        }
    }

    //    ListNode* recursive(ListNode* head, ListNode** new_head) {
    //        if (head->next) {
    //            ListNode* tail = recursive(head->next, new_head);
    //            tail->next = head;
    //            return head;
    //        } else {
    //            *new_head = head;
    //            return head;
    //        }
    //    }

};

int main() {
    Solution solution;

    ListNode *test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(3);
    test->next->next->next = new ListNode(4);
    test->next->next->next->next = new ListNode(5);

    ListNode *answer = solution.reverseList(test);
    ListNode *temp = answer;
    while (answer) {
        std::cout << answer->val << std::endl;
        answer = answer->next;
    }

    delete temp->next->next->next->next;
    delete temp->next->next->next;
    delete temp->next->next;
    delete temp->next;
    delete temp;

    return 0;
}

