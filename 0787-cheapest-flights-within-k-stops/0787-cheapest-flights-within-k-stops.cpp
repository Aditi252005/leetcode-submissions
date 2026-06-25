class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({0,{k+1,src}});

        vector<vector<int>> dis(n,vector<int>(k+2,INT_MAX));
        dis[src][k+1]=0;

        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();

            int p=node.first;
            int t=node.second.first;
            int curr=node.second.second;

            if(curr==dst) return p;
            if(p>dis[curr][t]) continue;
 
            for(auto [nbr,c]:adj[curr]){
                if(t>0 && dis[nbr][t-1]>p+c){
                    dis[nbr][t-1]=p+c;
                    pq.push({p+c,{t-1,nbr}});
                }
            }
        }
        return -1;
    }
};