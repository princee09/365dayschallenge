/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;

    void markParents(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front(); q.pop();
            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root);  // Step 1: Map child -> parent

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int currentDist = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currentDist == k) break;

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front(); q.pop();
                
                // Traverse left
                if (current->left && !visited.count(current->left)) {
                    visited.insert(current->left);
                    q.push(current->left);
                }

                // Traverse right
                if (current->right && !visited.count(current->right)) {
                    visited.insert(current->right);
                    q.push(current->right);
                }

                // Traverse parent
                if (parentMap.count(current) && !visited.count(parentMap[current])) {
                    visited.insert(parentMap[current]);
                    q.push(parentMap[current]);
                }
            }

            currentDist++;
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};
