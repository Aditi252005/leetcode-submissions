class Solution {
public:
    void f(TreeNode* root,int val){
        if(val<root->val){
            if(!root->left) {TreeNode*v=new TreeNode(val);root->left=v;return;}
            else return f(root->left,val);
        }else{
            if(!root->right) {TreeNode*v=new TreeNode(val);root->right=v;return;}
            else return f(root->right,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {TreeNode*v=new TreeNode(val);return v;}
        f(root,val);
        return root;
    }
};