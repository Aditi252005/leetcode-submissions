class Solution {
public:
    bool f(TreeNode* root,int targetSum){
        if(!root) return false;
        if(targetSum==root->val && !root->left && !root->right) return true;
        
        bool l=f(root->left,targetSum-root->val);
        bool r=f(root->right,targetSum-root->val);

        return l || r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root,targetSum);
    }
};