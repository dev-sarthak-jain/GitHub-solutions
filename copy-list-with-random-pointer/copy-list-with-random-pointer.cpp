/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL){return NULL;}
        unordered_map<Node*,Node*> map;
        map[NULL] = NULL;
        Node * now = new Node(head->val);
        map[head] = now;
        Node* temp1 = head->next, *temp2 = now;
        while(temp1!=NULL)
        {
            Node* ran = new Node(temp1->val);
            temp2->next = ran;
            map[temp1] = ran;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp2->next = NULL;
        temp1 = head,temp2 = now;
        while(temp1!=NULL)
        {
            temp2->random = map[temp1->random];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return now;
    }
};