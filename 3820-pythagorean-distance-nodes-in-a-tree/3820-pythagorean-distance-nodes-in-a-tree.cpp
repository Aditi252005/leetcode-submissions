class Solution {
public:
    vector<int> bfs(int s,vector<vector<int>>&adj,int n){
        vector<int> dist(n,-1);
        queue<int> q;
        dist[s]=0;
        q.push(s);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto neighbour:adj[node]){
                if(dist[neighbour]==-1){
                    dist[neighbour]=dist[node]+1;
                    q.push(neighbour);
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
       vector<vector<int>> adj(n);
       for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       } 

       vector<int> dx=bfs(x,adj,n),dy=bfs(y,adj,n),dz=bfs(z,adj,n);

        int ans=0;
       for(int i=0;i<n;i++){
        long long a=dx[i];
        long long b=dy[i];
        long long c=dz[i];
        if(a==-1 || b==-1 || c==-1) continue;

        if(a>=b && a>=c){
            if(a*a==(b*b + c*c)) ans++;
        }
        else if(b>=a && b>=c){
            if(b*b==(a*a + c*c)) ans++;
        }
        else if(c>=b && c>=a){
            if(c*c==(b*b + a*a)) ans++;
        }
       // cout<<i<<a<<b<<c<<endl;
       }
       return ans;
    }
};