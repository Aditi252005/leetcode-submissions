class Solution {
public:
    void f(int r,int c,TreeNode* root,unordered_map<int,vector<pair<int,int>>>&mp){
        if(!root) return;
        mp[c].push_back({r,root->val});
        f(r+1,c-1,root->left,mp);
        f(r+1,c+1,root->right,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<pair<int,int>>> mp;
        f(0,0,root,mp);

        vector<vector<int>> ans;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto it:mp){
            mini=min(mini,it.first);
            maxi=max(maxi,it.first);
        }
        for(int i=mini;i<=maxi;i++){
            vector<int> v;
            sort(mp[i].begin(),mp[i].end());
            for(auto num:mp[i]) v.push_back(num.second);
            ans.push_back(v);
        }
        return ans;
    }
};