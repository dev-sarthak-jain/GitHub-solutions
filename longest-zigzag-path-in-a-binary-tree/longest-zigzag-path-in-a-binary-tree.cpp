/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int m = 0;
    int explore(TreeNode* root, bool turn)
    {
        if (root == NULL){return 0;}
        int a = explore(root->left,1);
        int b = explore(root->right,0);
        m = max(m,max(a+1,b+1));
        if (turn == 0){return 1+a;}
        if (turn == 1){return 1+b;}
        return -1;
    }

    int longestZigZag(TreeNode* root) {
        int x = explore(root->left,1);
        int y = explore(root->right,0);
        cout << x << " " << y << " " << m << endl;
        return max(m,max(x+1,y+1)) - 1;
    }
};