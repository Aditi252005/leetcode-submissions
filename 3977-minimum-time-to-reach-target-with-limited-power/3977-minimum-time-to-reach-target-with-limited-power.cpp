class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int p, vector<int>& c, int s, int t) {
        vector<vector<pair<int,long long>>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<vector<long long>> dis(n,vector<long long>(p+1,4e18));
        dis[s][0]=0;

        priority_queue< tuple<long long,long long,int>, vector<tuple<long long,long long,int>>, greater<>> pq;
        pq.push({0,0,s});
        
        while(!pq.empty()){
            auto [t1,pused,node]=pq.top();
            pq.pop();


            if (node == t) {
               if(pused<=p) return {t1,p-pused};
            }
            
            if(pused+c[node]>p) continue;
            
            if(dis[node][pused]<t1) continue;

            for(auto [nbr,t2]:adj[node]){
                long long tp=pused+c[node];
                if(tp<=p && dis[nbr][tp]>t1+t2){
                    dis[nbr][tp]=t1+t2;
                    pq.push({t1+t2,tp,nbr});
                }
            }
        }
        return {-1,-1};
    }
};