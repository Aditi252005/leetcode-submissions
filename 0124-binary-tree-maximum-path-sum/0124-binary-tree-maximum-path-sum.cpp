class Solution {
public:
    int ans=INT_MIN;
    int f(TreeNode* root){
        if(!root) return 0;

        int l=f(root->left);
        int r=f(root->right);

        ans=max({ans,root->val,root->val+max(l,r),root->val+l+r});
        return max(root->val,root->val+max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};