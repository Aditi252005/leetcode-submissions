class Solution {
public:
     int d=1;
    int f(TreeNode*root){
        if(!root) return 0;

        int ld=f(root->left);
        int rd=f(root->right);

        d=max(d,ld+rd+1);
        return 1+max(ld,rd);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       
        f(root);
        return d-1;
    }
};