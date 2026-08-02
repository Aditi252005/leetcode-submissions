class Solution {
public:
    int maxs=INT_MIN;
    int f(TreeNode*root){
        if(!root) return 0;

        int ls=f(root->left);
        int rs=f(root->right);

        maxs=max({maxs,root->val,root->val+ls+rs,root->val+max(ls,rs)});

        return max(root->val,root->val+max(ls,rs));
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return maxs;
    }
};