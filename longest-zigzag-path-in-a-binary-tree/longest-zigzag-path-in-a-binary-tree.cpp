class Solution {
public:
    int m = 0;
    int explore(TreeNode* root, bool turn)
    {
        if (root == NULL){return 0;}
        int a = explore(root->left,1);
        int b = explore(root->right,0);
        m = max(m,max(a,b));
        if (turn == 0){return 1+a;}
        if (turn == 1){return 1+b;}
        return -1;
    }

    int longestZigZag(TreeNode* root) {
        int x = explore(root->left,1);
        int y = explore(root->right,0);
        return max(m,max(x,y));
    }
};