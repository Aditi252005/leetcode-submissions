class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        

        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }

       
        int maxMinEdge=-1;
        priority_queue<tuple<int,int,long long>> pq;
        if(online[0]) pq.push({INT_MAX,0,0});
        // minc,node,dist

        while(!pq.empty()){
            auto [minc,node,dist]=pq.top();
            pq.pop();
            
            if(node==n-1){
                maxMinEdge=max(maxMinEdge,minc);
                break;  //why break?
            }

            for(auto neighbour:adj[node]){
                int nnode=neighbour.first;
                int nt=neighbour.second;
                if(dist+nt<=k && online[nnode]){
                    pq.push({min(minc,nt),nnode,dist+nt}); 
                }
            }
        }

       return maxMinEdge;
    }
};