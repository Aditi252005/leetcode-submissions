class Solution {
public:
    TreeNode* v;
    void f(TreeNode* root,int val){
        if(root->val>val && !root->left) {root->left=v;return;}
        else if(root->val<val && !root->right) {root->right=v;return;}

        if(root->val>val) f(root->left,val);
        else f(root->right,val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        v=new TreeNode(val);
        if(!root) return v;
        f(root,val);

        return root;        
    }
};