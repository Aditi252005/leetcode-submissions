class Solution {
public:
    void dfs(int i,vector<vector<int>>& graph,vector<int>&v,vector<vector<int>>& ans){
        int n=graph.size();
        if(i==n-1){
            v.push_back(n-1);
            ans.push_back(v);
            return;
        }
        v.push_back(i);
        for(int j=0;j<graph[i].size();j++){
            dfs(graph[i][j],graph,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        vector<vector<int>> ans;
        vector<int> v;
        dfs(0,graph,v,ans);
        return ans;
    }
};