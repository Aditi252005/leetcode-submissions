class Solution {
public:
    TreeNode* f(TreeNode* root,int nidx,map<int,int>& mp){
        if(!root) return NULL;

        if(!root->left && !root->right) return root;

        if(nidx < mp[root->val]){
            if(root->left) return f(root->left,nidx,mp);
            return root;
        }

        if(root->right) return f(root->right,nidx,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[in[i]]=i;

        TreeNode* root= new TreeNode(pre[0]);
        int i=1;
        while(i<n){
            TreeNode* nnode= new TreeNode(pre[i]);
            int nidx=mp[pre[i]];

            TreeNode* par=f(root,nidx,mp);

            if(nidx<mp[par->val]) par->left=nnode;
            else par->right=nnode;

            i++;            
        }

        return root;
    }
};