class Solution {
public:
    int m = 0;
    int recur(TreeNode* root){
        if (root == NULL){return 0;}
        int a=-1,b=-1;
        if (root->left){a = recur(root->left);}
        if (root->right){b = recur(root->right);}
        m = max(m,a+b+2);
        return 1 + max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return max(recur(root),m);
    }
};