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
    unordered_set<ListNode*> s;
    bool hasCycle(ListNode *head) {
        if (head == NULL){return 0;}

        if (s.find(head) == s.end())
        {
            s.insert(head);
            return hasCycle(head->next);
        }
        else
        {
            return 1;
        }
    }
};