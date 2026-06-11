class Solution {
public:
    int dfs(int node,int p,vector<vector<int>>&adj){
        if(adj[node].size()==0) return 0;

        int ans=0;
        for(auto neigh:adj[node]){
            if(neigh!=p) ans=max(ans,1+dfs(neigh,node,adj));
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+2;
        vector<vector<int>> adj(n);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        
        int maxd=dfs(1,-1,adj);
        maxd--;

        int ans=1;

        while(maxd--){
            ans=(2*ans)%1000000007;
        }

        return ans;
        
    }
};