class Solution {
public:
    TreeNode* f(TreeNode* root,int nidx,map<int,int>&mp){
        if(!root->left && !root->right) return root;

        if(mp[root->val]<nidx){
            if(root->right) return f(root->right,nidx,mp);
            return root;
        }
        if(root->left) return f(root->left,nidx,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        map<int,int> mp;

        for(int i=0;i<n;i++) mp[in[i]]=i;
        TreeNode* root=new TreeNode(post[n-1]);

        int i=n-2;
        while(i>=0){
            TreeNode* nnode= new TreeNode(post[i]);
            int nidx=mp[post[i]];

            TreeNode* par=f(root,nidx,mp);
            if(mp[par->val]<nidx) par->right=nnode;
            else par->left=nnode;

            i--;
        }
        return root;
    }
};