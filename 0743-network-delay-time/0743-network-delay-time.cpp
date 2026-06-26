class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto t:times){
            adj[t[0]].push_back({t[1],t[2]});
        }

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,k});

        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        set<int> st;
        st.insert(k);
        st.insert(0);
        int ans=0;

        while(!pq.empty()){
            auto [time,node]=pq.top();
            pq.pop();

            if(dis[node]<time) continue;
            ans=max(ans,time);
            st.insert(node);
            if(st.size()==n+1) return ans;

            for(auto [nbr,t]:adj[node]){
                if(dis[nbr]>time+t){
                    dis[nbr]=time+t;
                    pq.push({dis[nbr],nbr});
                }
            }
        }
        return -1;
    }
};