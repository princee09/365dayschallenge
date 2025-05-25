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
    int maxDiameter = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        // Update diameter at this node
        maxDiameter = max(maxDiameter, left + right);

        // Return height of current node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }
};
