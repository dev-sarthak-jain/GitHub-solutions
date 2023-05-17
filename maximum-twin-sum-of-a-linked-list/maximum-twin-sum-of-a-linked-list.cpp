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
    int m = 0;
    ListNode* temp;
    void recur(ListNode* head)
    {
        if(temp->next == NULL)
        {
            temp = head->next;
            m = head->val + temp->val;
            return;
        }
        temp = temp->next->next;
        recur(head->next);
        temp = temp->next;
        head->val += temp->val;
        m = head->val>m?head->val:m;
    }

    int pairSum(ListNode* head) {
        temp = head->next;
        recur(head);
        return m;
    }
};