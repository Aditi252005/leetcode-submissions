class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        vector<set<int>> v(n);

        for(int i=0;i<n;i++){
            priority_queue< pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            pq.push({0,i});

            vector<int> dis(n,INT_MAX);
            dis[i]=0;

            while(!pq.empty()){
                auto [t,node]=pq.top();
                pq.pop();

                if(t>dt) break;
                if(dis[node]<t) continue;
                v[i].insert(node);

                for(auto [nbr,c]:adj[node]){
                    if(dis[nbr]>t+c){
                        dis[nbr]=t+c;
                        pq.push({dis[nbr],nbr});
                    }
                }
            }
        }

        int minn=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[i].size()==minn){
                ans=max(ans,i);
            }
            else if(v[i].size()<minn) {
                minn=v[i].size();
                ans=i;
            }
        }
        return ans;
    }
};