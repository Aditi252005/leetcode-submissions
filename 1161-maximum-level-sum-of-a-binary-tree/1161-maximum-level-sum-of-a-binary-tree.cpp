class Solution {
public:
    void dfs(TreeNode* root,int l,map<int,long long>&mp){
        if(!root) return;
        mp[l]+=root->val;
        dfs(root->left,l+1,mp);
        dfs(root->right,l+1,mp);
    }
    int maxLevelSum(TreeNode* root) {
        int l=1;
        map<int,long long> mp;
        dfs(root,l,mp);

        int maxs=INT_MIN,ans=1;
        for(auto it:mp){
            if(it.second>maxs){
                maxs=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};