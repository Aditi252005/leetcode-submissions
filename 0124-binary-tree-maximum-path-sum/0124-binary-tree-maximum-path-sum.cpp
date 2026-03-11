class Solution {
public:
    
    int f(TreeNode* root,int&ans){
        if(!root) return 0;
        
        int l=max(0,f(root->left,ans));
        int r=max(0,f(root->right,ans));
 
        ans=max(ans,root->val+l+r);

        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        int a=f(root,ans);
        
        return ans;
    }
};