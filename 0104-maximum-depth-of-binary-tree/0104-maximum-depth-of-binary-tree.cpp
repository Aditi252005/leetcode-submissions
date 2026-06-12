class Solution {
public:
    int f(TreeNode* root){
        if(!root) return 0;

        return 1+max(f(root->left),f(root->right));
    }
    int maxDepth(TreeNode* root) {
        return f(root);
    }
};