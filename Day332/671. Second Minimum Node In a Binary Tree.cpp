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
    int findSecondMinimumValue(TreeNode* root) {
        return dfs(root, root->val);
    }
private:
    int dfs(TreeNode* node, int minVal) {
        if (!node) return -1;
        if (node->val > minVal) {
            return node->val;
        }
        int left = dfs(node->left, minVal);
        int right = dfs(node->right, minVal);
        if (left != -1 && right != -1) {
            return min(left, right);
        }
        if (left != -1) return left;
        if (right != -1) return right;
        return -1;
    }
};