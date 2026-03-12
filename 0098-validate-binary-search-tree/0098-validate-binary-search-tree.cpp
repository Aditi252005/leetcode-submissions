class Solution {
public:
    bool f(TreeNode* root,long minv,long maxv){
        if(!root) return true;
       // if(root->val<=minv || root->val>=maxv) return false;

        bool l=f(root->left,minv,root->val);
        if(root->val<=minv) return false;

        bool r=f(root->right,root->val,maxv);
        if(root->val>=maxv) return false;

        return l&&r;
    }

    bool isValidBST(TreeNode* root) {
        return f(root,LONG_MIN,LONG_MAX);
    }
};