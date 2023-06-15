/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL){return 0;}
        ListNode* fast = head;
        ListNode* slow = head;
        while(1)
        {
            if (fast->next != NULL && fast->next->next!=NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            else{return 0;}

            if (fast == slow){return 1;}
        }
    }
};