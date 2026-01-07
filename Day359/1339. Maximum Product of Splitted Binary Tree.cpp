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
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        vector<long> sums;
        long total = dfs(root, sums);
        long maxProd = 0;
        
        for (long sum : sums) {
            maxProd = max(maxProd, sum * (total - sum));
        }
        
        return maxProd % MOD;
    }
    
private:
    long dfs(TreeNode* node, vector<long>& sums) {
        if (!node) return 0;
        long sum = node->val + dfs(node->left, sums) + dfs(node->right, sums);
        sums.push_back(sum);
        return sum;
    }
};