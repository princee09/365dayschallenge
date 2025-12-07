struct RobResult {
    int withRob;   
    int withoutRob; 
};
class Solution {
public:
    int rob(TreeNode* root) {
        RobResult result = dfs(root);
        return max(result.withRob, result.withoutRob);
    } 
private:
    RobResult dfs(TreeNode* node) {
        if (!node) return {0, 0};
        
        RobResult left = dfs(node->left);
        RobResult right = dfs(node->right);
        int robThis = node->val + left.withoutRob + right.withoutRob;
        int skipThis = max(left.withRob, left.withoutRob) + 
                      max(right.withRob, right.withoutRob);
        
        return {robThis, skipThis};
    }
};