class Solution {
public:
    vector<int> v;
    void f(TreeNode* root){
        if(!root) return;

        v.push_back(root->val);
        f(root->left);
        f(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        f(root);
        return v;
    }
};