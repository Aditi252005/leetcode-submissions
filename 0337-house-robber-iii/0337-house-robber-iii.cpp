class Solution {
public:
    int f(TreeNode*root,map<TreeNode*,int>&dp){
        if(!root) return 0;
        if(dp.count(root)) return dp[root];

        int take= root->val;
        if(root->left) take+= f(root->left->left,dp)+f(root->left->right,dp);
        if(root->right) take+= f(root->right->left,dp)+f(root->right->right,dp);

        int skip= f(root->left,dp)+f(root->right,dp);

        return dp[root]=max(take,skip);
    }
    int rob(TreeNode* root) {
        
        map<TreeNode*,int> dp;
        return f(root,dp);
    }
};