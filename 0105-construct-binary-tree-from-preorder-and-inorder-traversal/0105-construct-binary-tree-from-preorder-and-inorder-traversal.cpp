class Solution {
public:
    int idx=0;
    TreeNode* build(vector<int>&pre,map<int,int>&mp,int st,int end){
        if(st>end) return NULL;
        TreeNode* root=new TreeNode(pre[idx++]);

        int mid=mp[root->val];
        root->left=build(pre,mp,st,mid-1);
        root->right=build(pre,mp,mid+1,end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++) mp[inorder[i]]=i;

        return build(preorder,mp,0,n-1);
    }
};