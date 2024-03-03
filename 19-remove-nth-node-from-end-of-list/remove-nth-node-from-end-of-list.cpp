class Solution {
public:
    int check;
    bool deleted = 0;
    void recur(ListNode* head)
    {
        if (head == NULL){return;}
        recur(head->next);
        if (check == 0)
        {
            deleted = 1;
            check--;
            if (head->next == NULL)
            {
                return;
            }
            else
            {
                head->next = head->next->next;
                return;
            }
        }
        check--;
        return;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        check = n;
        recur(head);
        if (deleted){return head;}
        else{return head->next;}
    }
};