class Solution {
public:
    int dfs(int i,vector<vector<int>>&adj,vector<int>&vis){
        if(vis[i]) return 0;
        vis[i]=1;
        int count=0;
        for(auto nbr:adj[i]){
           count+=dfs(nbr,adj,vis);
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
                int tnodes=dfs(i,adj,vis);
                queue<int> q;
                q.push(i);
                set<int> st;
                bool check=true;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();

                    if(st.count(node)) continue;
                    st.insert(node);
                    if(adj[node].size()!=tnodes-1) {check=false;break;}
                    for( auto nbr:adj[node]) q.push(nbr);
                }

                if(check) ans++;
            }
        }

        return ans;
    }
};