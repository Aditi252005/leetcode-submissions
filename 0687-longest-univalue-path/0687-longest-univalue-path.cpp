class Solution {
public:
    int f(TreeNode* root,int& ans){
        if(!root) return 0;

        int left=f(root->left,ans);
        int right=f(root->right,ans);

        int l=0,r=0;

        if(root->left && root->left->val==root->val) l=left+1;
        if(root->right && root->right->val==root->val) r=right+1;


        ans=max(ans,l+r);
        return max(l,r);
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        f(root,ans);
        return ans;
    }
};