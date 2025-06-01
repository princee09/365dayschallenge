class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* node = nullptr;

            for (int i = 0; i < levelSize; ++i) {
                node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // The last node at the current level is the rightmost one
            result.push_back(node->val);
        }

        return result;
    }
};
