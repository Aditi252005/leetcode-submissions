class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        q.push({headID,-1});
        int ans=0;
        vector<int> t(n,0);
       

        while(!q.empty()){
            int node=q.front().first;
            int p=q.front().second;
            q.pop();
            
            if(p!=-1) t[node]=t[p]+informTime[p];
            ans=max(ans,t[node]);

            for(auto neigh:adj[node]){
                q.push({neigh,node});
            }

        }
        return ans;
    }
};