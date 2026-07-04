class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }

        queue<pair<int,int>> q;
        q.push({1,INT_MAX});
        vector<bool> vis(n+1,false);
        int ans=INT_MAX;

        while(!q.empty()){
            auto [node,d]=q.front();
            q.pop();

            vis[node]=true;
            ans=min(ans,d);

            for(auto [nbr,c]:adj[node]){
                if(!vis[nbr]) q.push({nbr,c});
            }
        }

        if(vis[n]) return ans;
        return -1;
    }
};