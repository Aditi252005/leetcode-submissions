class Solution {
public:
    bool check(int w,vector<vector<pair<int,int>>>&adj,vector<bool>& online, long long k){
        int n=online.size();

        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;
        pq.push({0,0});

        vector<long long> dis(n,LLONG_MAX);
        dis[0]=0;

        while(!pq.empty()){
            auto [tc,node]=pq.top();
            pq.pop();

            if(dis[node]<tc) continue;

            for(auto [nbr,c]:adj[node]){
                if(!online[nbr] || c<w) continue;
                if(dis[nbr]>tc+c && tc+c<=k){
                    dis[nbr]=tc+c;
                    pq.push({tc+c,nbr});
                }
            }
        }

        return dis[n-1]<=k;

    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        
        vector<vector<pair<int,int>>> adj(n);
        int maxew=0;
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            maxew=max(maxew,e[2]);
        }

       
        int lo=0;
        int hi=maxew;
        int ans=-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(check(mid,adj,online,k)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        return ans;
    }
};