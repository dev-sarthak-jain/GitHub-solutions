class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL){return NULL;}
        queue<Node *> que;
        que.push(root);
        while(que.size()!=0)
        {
            int n = que.size();
            que.push(NULL);
            for(int i=0;i<n;i++)
            {
                Node * temp = que.front();
                que.pop();
                //cout << temp->val << endl;
                temp->next = que.front();
                if (temp->left!=NULL)que.push(temp->left);
                if (temp->right!=NULL)que.push(temp->right);
            }
            que.pop();
        }
        return root;
    }
};