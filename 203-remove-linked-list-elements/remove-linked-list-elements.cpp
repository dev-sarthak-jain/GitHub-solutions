/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int num) {
        if (head == NULL){return head;}
        while(head !=NULL && head->val == num){head = head->next;}
        ListNode* temp = head;
        while(temp!=NULL && temp->next!=NULL)
        {
            if (temp->next->val == num){
                temp->next = temp->next->next;
            }
            else{temp = temp->next;}
        }
        return head;
    }
};