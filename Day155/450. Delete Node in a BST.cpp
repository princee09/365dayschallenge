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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            // Search in left subtree
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // Search in right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // Node found
            if (!root->left) return root->right; // Only right child or no child
            if (!root->right) return root->left; // Only left child

            // Node with two children: find inorder successor (smallest in right subtree)
            TreeNode* minNode = findMin(root->right);
            root->val = minNode->val; // Copy the value
            root->right = deleteNode(root->right, minNode->val); // Delete the inorder successor
        }

        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
};
