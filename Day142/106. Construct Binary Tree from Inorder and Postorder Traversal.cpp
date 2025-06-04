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
    unordered_map<int, int> inorderIndexMap;
    int postIdx;

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int index = inorderIndexMap[rootVal];

        // Build right subtree before left subtree
        root->right = helper(inorder, postorder, index + 1, inRight);
        root->left = helper(inorder, postorder, inLeft, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = postorder.size() - 1;

        // Build a value -> index map for inorder to avoid O(n) lookups
        for (int i = 0; i < inorder.size(); ++i)
            inorderIndexMap[inorder[i]] = i;

        return helper(inorder, postorder, 0, inorder.size() - 1);
    }
};
