class Solution {
public:
    int f(int l,TreeNode* root,map<TreeNode*,int>& dp){
        if(!root) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];

        int a=0,b=0,c=0,d=0;
        if(root->left){
           a=f(l+2,root->left->left,dp);  
           b=f(l+2,root->left->right,dp);
        } 
       
        if(root->right){
          c=f(l+2,root->right->left,dp);  
          d=f(l+2,root->right->right,dp);
        } 
       

        int take= root->val+a+b+c+d;
        int skip=f(l+1,root->left,dp)+f(l+1,root->right,dp);

        return dp[root]= max(take,skip);

    }
    
    int rob(TreeNode* root) {
      map<TreeNode*,int> dp;
        return f(1,root,dp);
    }
};