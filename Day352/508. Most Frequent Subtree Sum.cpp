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
private:
    unordered_map<int, int> freq;
    int maxFreq = 0;
    
    int calculateSubtreeSum(TreeNode* node) {
        if (!node) return 0;
        int leftSum = calculateSubtreeSum(node->left);
        int rightSum = calculateSubtreeSum(node->right);
        int total = leftSum + rightSum + node->val;
        freq[total]++;
        maxFreq = max(maxFreq, freq[total]);
        return total;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        calculateSubtreeSum(root); 
        vector<int> result;
        for (const auto& pair : freq) {
            if (pair.second == maxFreq) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }
};