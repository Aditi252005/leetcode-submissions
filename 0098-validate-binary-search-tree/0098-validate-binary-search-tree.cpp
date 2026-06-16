class Solution {
public:
    bool f(TreeNode* root,long long mini,long long maxi){
        if(!root) return true;
        if(root->val<=mini || root->val>=maxi) return false;

        bool l= f(root->left,mini,root->val);
        bool r= f(root->right,root->val,maxi);
        return l&&r;
    }
    bool isValidBST(TreeNode* root) {
        return f(root,LLONG_MIN,LLONG_MAX);
    }
};