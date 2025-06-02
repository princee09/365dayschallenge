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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long max_width = 0;
        
        while (!q.empty()) {
            unsigned long long level_size = q.size();
            unsigned long long first_index = q.front().second;
            unsigned long long last_index = q.back().second;
            max_width = max(max_width, last_index - first_index + 1);
            
            for (unsigned long long i = 0; i < level_size; ++i) {
                auto [node, index] = q.front();
                q.pop();
                unsigned long long adjusted_index = index - first_index;
                
                if (node->left) {
                    q.push({node->left, 2 * adjusted_index});
                }
                if (node->right) {
                    q.push({node->right, 2 * adjusted_index + 1});
                }
            }
        }
        
        return max_width;
    }
};