class Solution {
public:
    int f(TreeNode* root,int k,int& a,int& ans){
        if(!root) return a;

        int l=f(root->left,k,a,ans);
        a=l+1;
        if(a==k) ans=root->val;
        int r=f(root->right,k,a,ans);

        return a;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int a=0;
        f(root,k,a,ans);
        return ans;
    }
};