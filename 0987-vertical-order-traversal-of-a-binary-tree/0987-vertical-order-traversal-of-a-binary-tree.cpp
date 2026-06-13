class Solution {
public:
    void dfs(TreeNode* node,int r,int c,map<int,vector<pair<int,int>>>&mp,int l){
        if(!node) {return;}

        mp[c].push_back({r,node->val});
        
        dfs(node->left,r+1,c-1,mp,l+1);
        dfs(node->right,r+1,c+1,mp,l+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> mp;
        
        dfs(root,0,0,mp,0);

        for(auto&[c,vec]:mp){
            sort(vec.begin(),vec.end());
            vector<int> v;
            for(auto& it:mp[c]) v.push_back(it.second);
            ans.push_back(v);
        }
        
        return ans;
    }
};