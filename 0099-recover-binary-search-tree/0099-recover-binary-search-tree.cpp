/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* a=NULL;
    TreeNode* b=NULL;
    TreeNode* prev=NULL;
    void f(TreeNode* root){
        if(!root) return;
        f(root->left);
        if(prev && prev->val>root->val){
            if(!a) a=prev;
            b=root;
        }
        prev=root;
        f(root->right);
    }
    void recoverTree(TreeNode* root) {
        f(root);
        if(a && b) swap(a->val,b->val);
    }
};