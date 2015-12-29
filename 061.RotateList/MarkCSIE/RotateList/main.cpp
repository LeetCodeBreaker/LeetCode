#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
public:

    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *current = head;

        int listLength = 0;
        ListNode *anchor = nullptr;
        while (true) {
            if (current->next == nullptr) {
                current->next = head;
                k %= listLength + 1;
                int anchorIndex = listLength - k + 1;
                for (int i = 0; i < anchorIndex; i++) {
                    current = current->next;
                }
                anchor = current->next;
                current->next = nullptr;
                break;
            }
            current = current->next;
            listLength++;
        }
        return anchor;
    }
    
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode *rotatedHead = solution.rotateRight(head, 2);
    while (rotatedHead) {
        std::cout << rotatedHead->val << " ";
        ListNode *temp = rotatedHead;
        rotatedHead = rotatedHead->next;
        delete temp;
    }
    
    return 0;
}