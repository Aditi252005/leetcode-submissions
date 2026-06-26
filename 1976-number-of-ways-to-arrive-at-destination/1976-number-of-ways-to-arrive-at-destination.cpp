class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }

        vector<long long> dis(n,LLONG_MAX);
        dis[0]=0;

        vector<long long> ways(n,0);
        ways[0]=1;

        priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();

            
            if(dis[node]<t) continue;

            for(auto [nbr,c]:adj[node]){
                if(dis[nbr]==c+t) ways[nbr]=(ways[node]+ways[nbr])%1000000007;
                else if(dis[nbr]>c+t){
                    dis[nbr]=c+t;
                    ways[nbr]=ways[node];
                    pq.push({dis[nbr],nbr});
                }
            }
        }
        return ways[n-1];
    }
};