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

        int value1, value2;

        struct ListNode *preNode = NULL;
        struct ListNode *HeadNode = NULL;
        struct ListNode *FirstList = l1;
        struct ListNode *SecondList = l2;

        while(!(FirstList == NULL && SecondList == NULL)) 
        {
            if(FirstList == NULL) {
                value1 = 0;
            }
            else {
                value1 = FirstList->val;
            }
            if(SecondList == NULL) {
                value2 = 0;
            }
            else {
                value2 = SecondList->val;
            }

            struct ListNode *Node =  new ListNode(value1 + value2);

            if(preNode != NULL) {
                preNode->next = Node;
            }
            else {
                HeadNode = Node;
            }
            
            preNode = Node;

            FirstList = FirstList->next;
            SecondList = SecondList->next;
        }

        ListNode *NodeNow = HeadNode; 
        while(NodeNow != NULL) 
        {
            int ret = (NodeNow->val) / 10;
            NodeNow->val = (NodeNow->val) % 10;
            if(NodeNow->next != NULL) {
                (NodeNow->next)->val += r/et;
            }
            else {
                if(ret > 0) {
                    NodeNow->next = new ListNode(ret);
                }
            }

            NodeNow = NodeNow->next;

        }

        return HeadNode;
};
int main() 
{
    Solution sol;
    return 0;    
}
