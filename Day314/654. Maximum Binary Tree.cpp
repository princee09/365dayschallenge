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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> nodes;
        
        for (int num : nums) {
            TreeNode* node = new TreeNode(num);
            while (!nodes.empty() && nodes.back()->val < num) {
                node->left = nodes.back();
                nodes.pop_back();
            }
            
            if (!nodes.empty()) {
                nodes.back()->right = node;
            }
            
            nodes.push_back(node);
        }
        
        return nodes[0]; 
    }
};