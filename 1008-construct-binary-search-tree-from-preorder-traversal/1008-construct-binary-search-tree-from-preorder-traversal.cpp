class Solution {
public:
    TreeNode* f(TreeNode* root,int val){
        if(!root->right && !root->left) return root;

        if(val<root->val) {
            if(!root->left) return root;
            return f(root->left,val);
        }

        if(!root->right) return root;
        return f(root->right,val);
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n=pre.size();
        TreeNode* root= new TreeNode(pre[0]);

        int i=1;
        while(i<n){
            TreeNode* nnode= new TreeNode(pre[i]); 
            TreeNode* p=f(root,pre[i]);
            if(nnode->val<p->val) p->left=nnode;
            else p->right=nnode;

            i++;
        }
        return root;
    }
};