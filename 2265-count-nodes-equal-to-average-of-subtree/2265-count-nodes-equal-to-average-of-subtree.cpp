
class Solution {
public:
    pair<int,int> f(TreeNode* root){
        if(!root) return {0,0};

        auto [ls,ln]=f(root->left);
        auto [rs,rn]=f(root->right);

        if(root->val==(ls+rs+root->val)/(ln+rn+1)) count++;

        return {root->val+ls+rs,ln+rn+1};
    }
    int count=0;
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return count;
    }
};