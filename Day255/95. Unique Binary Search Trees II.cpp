/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};

        vector<vector<vector<TreeNode*>>> dp(n + 2,
                                             vector<vector<TreeNode*>>(n + 2));

        return generateTrees(1, n, dp);
    }

private:
    vector<TreeNode*> generateTrees(int start, int end,
                                    vector<vector<vector<TreeNode*>>>& dp) {
        if (start > end) {
            return {nullptr};
        }

        if (!dp[start][end].empty()) {
            return dp[start][end];
        }

        vector<TreeNode*> result;

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubtrees = generateTrees(start, i - 1, dp);
            vector<TreeNode*> rightSubtrees = generateTrees(i + 1, end, dp);
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        dp[start][end] = result;
        return result;
    }
};