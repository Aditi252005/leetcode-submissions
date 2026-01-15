class Solution {
public:
    int f(TreeNode* root,int v){
        if(!root) return 0;
        int ans=0;
        if(root->val>=v) ans++;
        return ans+f(root->left,max(root->val,v))+f(root->right,max(root->val,v));
    }
    int goodNodes(TreeNode* root) {
        return f(root,root->val);
    }
};