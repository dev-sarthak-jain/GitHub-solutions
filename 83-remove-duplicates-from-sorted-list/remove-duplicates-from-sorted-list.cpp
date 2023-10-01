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
    unordered_set<int> s;
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL){return head;}
        s.insert(head->val);
        ListNode* temp = head;
        while(temp->next != NULL)
        {
            if (s.find(temp->next->val) != s.end())
            {
                if (temp->next->next == NULL){temp->next = NULL;return head;}
                else {temp->next = temp->next->next;}
            }
            else{
                s.insert(temp->next->val);
                temp = temp->next;
            }
        }
        return head;
    }
};