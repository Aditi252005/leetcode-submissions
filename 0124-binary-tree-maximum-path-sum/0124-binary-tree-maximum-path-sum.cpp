class Solution {
public:
    int f(TreeNode* root,int&ans){
        if(!root) return 0;

        int l=f(root->left,ans);
        int r=f(root->right,ans);

        ans=max({ans,root->val+l+r,root->val,root->val+max(l,r)});

        return max(root->val+max(l,r),root->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        f(root,ans);
        return ans;
    }
};