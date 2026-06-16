class Solution {
public:
    int ans=0;
    void f(TreeNode* root,int& k){
        if(!root) return;
        
        f(root->left,k);
        k--;
        if(k==0) {ans=root->val;}
        f(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        f(root,k);
        return ans;
    }
};