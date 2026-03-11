class Solution {
public:
    int f(TreeNode* root,int& ans){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        int l=f(root->left,ans);
        int r=f(root->right,ans);

        ans=max(ans,l+r);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
       int a=f(root,ans);
       return ans;
    }
};