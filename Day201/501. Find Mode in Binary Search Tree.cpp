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
    int currentVal;
    int currentCount = 0;
    int maxCount = 0;
    vector<int> modes;

    void handleValue(int val) {
        if (val != currentVal) {
            currentVal = val;
            currentCount = 0;
        }
        currentCount++;

        if (currentCount > maxCount) {
            maxCount = currentCount;
            modes = {currentVal};  
        } else if (currentCount == maxCount) {
            modes.push_back(currentVal);  
        }
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        handleValue(root->val);
        inorder(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        currentCount = 0;
        maxCount = 0;
        currentVal = 0;
        modes.clear();

        inorder(root);
        return modes;
    }
};
