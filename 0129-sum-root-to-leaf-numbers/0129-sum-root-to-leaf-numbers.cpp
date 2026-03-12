class Solution {
public:
    int f(TreeNode* root,int n){
        if(!root) return 0;

        n=n*10+root->val;

        if(!root->left && !root->right) return n;

        int l=f(root->left,n);
        int r=f(root->right,n);

        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        return f(root,0);
    }
};