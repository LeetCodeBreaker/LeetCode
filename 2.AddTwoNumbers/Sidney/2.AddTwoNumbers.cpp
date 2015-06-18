#include <stdio.h>

/**
 *
 *  * Definition for singly-linked list.
 *
 *   * struct ListNode {
 *
 *    *     int val;
 *
 *     *     ListNode *next;
 *
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *
 *       * };
 *
 *        */
struct ListNode {

    int val;

    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

    public:

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            int value1, value2;
            struct ListNode *preNode = NULL;
            struct ListNode *HeadNode = NULL;
            while(l1->next == NULL && l2->next == NULL) 
            {
                if(l1->next == NULL) {
                    value1 = 0;
                }
                else {
                    value1 = l1->val;
                }
                if(l2->next == NULL) {
                    value2 = 0;
                }
                else {
                    value2 = l2->val;
                }
                struct ListNode *Node =  new ListNode(value1 + value2);
                if(preNode != NULL) {
                    preNode->next = Node;
                }
                else {
                    HeadNode = Node;
                }
            }

            ListNode *NodeNow = HeadNode; 
            while(NodeNow != NULL) 
            {
                int ret = (NodeNow->val) / 10;
                NodeNow->val = (NodeNow->val) % 10;
                if(NodeNow->next != NULL) {
                    (NodeNow->next)->val += ret;
                }
                else {
                    if(ret > 0) {
                        NodeNow->next = new ListNode(ret);
                    }
                }
                NodeNow = NodeNow->next;
            }




        }

};
int main() 
{
    Solution sol;
    return 0;    
}
