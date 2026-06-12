class Solution {
public:
    int f(TreeNode* root ,int& ans){
        if(!root) return 0;

        int l=f(root->left,ans);
        int r=f(root->right,ans);

        ans=max(ans,l+r);

        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        f(root,ans);
        return ans;
    }
};