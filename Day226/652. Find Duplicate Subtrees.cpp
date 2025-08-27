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
    unordered_map<string, int> subtreeCount; 
    vector<TreeNode*> result;
    string serialize(TreeNode* node) {
        if (!node) return "#"; 
        string left = serialize(node->left);
        string right = serialize(node->right);
        string subTree = to_string(node->val) + "," + left + "," + right;
        if (subtreeCount[subTree] == 1) {
            result.push_back(node);
        }
        subtreeCount[subTree]++;
        return subTree;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root); 
        return result;
    }
};
