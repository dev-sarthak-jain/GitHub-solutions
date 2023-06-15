class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int m = root->val;
        int x = 1;
        int y = 1;
        int n;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            n = que.size();
            int temp = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* current = que.front();
                que.pop();

                temp += current->val;

                if (current->left) {
                    que.push(current->left);
                }

                if (current->right) {
                    que.push(current->right);
                }
            }

            if (temp > m) {
                m = temp;
                x = y;
            }

            y++;
        }

        return x;
    }
};

