class Solution {
public:
    int dfs(int i,int& tedge,vector<vector<int>>&adj,vector<int>&vis){
        if(vis[i]) return 0;
        vis[i]=1;
        int count=0;
        tedge+=adj[i].size();
        for(auto nbr:adj[i]){
           count+=dfs(nbr,tedge,adj,vis);
        }
        return 1+count;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);
        int ans=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                int tedge=0;
                int tnodes=dfs(i,tedge,adj,vis);
                
                if(tedge== (tnodes*(tnodes-1))) ans++;
            }
        }

        return ans;
    }
};