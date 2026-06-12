class Solution {
public:
    int f(TreeNode* root){
        if(!root) return 0;
        return 1+max(f(root->left),f(root->right));
    }
    bool check(TreeNode* root){
        if(!root) return true;

        int l=f(root->left);
        int r=f(root->right);

        if(abs(l-r)>1) return false;
        return check(root->left) && check(root->right);
    }
    bool isBalanced(TreeNode* root) {
        return check(root);
    }
};