class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL){return head;}
        ListNode* prev = head;
        ListNode* curr = head->next;
        prev->next = NULL;
        while(curr!=NULL)
        {
            head = curr->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        return prev;

    }
};