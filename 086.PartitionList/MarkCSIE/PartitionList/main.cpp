
// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
public:

    ListNode* partition(ListNode* head, int x) {
        ListNode* current = head;
        ListNode* prev = nullptr;

        ListNode* exchangeHead = nullptr;
        bool exchange = false;
        while (current != nullptr) {
            if (current->val >= x && !exchange) {
                exchangeHead = prev;
                exchange = true;
            } else if (current->val < x && exchange) {
                ListNode* temp = nullptr;
                if (exchangeHead != nullptr) {
                    temp = exchangeHead->next;
                    exchangeHead->next = current;
                } else {
                    temp = head;
                    head = current;
                }
                prev->next = current->next;
                current->next = temp;

                exchange = false;
            }
            prev = current;
            current = current->next;
        }
        return head;
    }
};

int main() {
    Solution solution;
    return 0;
}