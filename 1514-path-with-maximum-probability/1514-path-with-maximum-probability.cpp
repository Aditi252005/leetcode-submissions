class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& ed, vector<double>& p, int s, int e) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<ed.size();i++){
            adj[ed[i][0]].push_back({ed[i][1],p[i]});
            adj[ed[i][1]].push_back({ed[i][0],p[i]});
        } 

        priority_queue<pair<double,int>> pq;
        pq.push({1.0,s});

        vector<double> dis(n,0.0);
        dis[s]=1.0;

        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();

            if(node==e) return t;
            if(dis[node]>t) continue;

            for(auto [nbr,c]:adj[node]){
                if(dis[nbr]<t*c){
                    dis[nbr]=t*c;
                    pq.push({dis[nbr],nbr});
                }
            }
        }
        return 0;
    }
};