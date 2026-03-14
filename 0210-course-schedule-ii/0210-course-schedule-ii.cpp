class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        int m=pre.size();
        vector<int> d(n,0);
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> ans;

        for(int i=0;i<m;i++){
            d[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        for(int i=0;i<n;i++) if(d[i]==0) q.push(i);

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            ans.push_back(curr);

            for(auto neigh:adj[curr]){
                d[neigh]--;
                if(d[neigh]==0) q.push(neigh);
            }
        }
        if(ans.size()==n) return ans;
        return {};
    }
};