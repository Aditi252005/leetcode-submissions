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
    void f(TreeNode* root,int& ans,int& p){
        if(!root) return;

        f(root->left,ans,p);
        if(p!=-1) ans=min(ans,root->val-p);
        p=root->val;
        f(root->right,ans,p);
    }
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        int p=-1;
        f(root,ans,p);
        return ans;
    }
};