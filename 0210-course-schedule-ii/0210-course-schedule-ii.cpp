class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        int m=pre.size();
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(int i=0;i<m;i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            ind[pre[i][0]]++;
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ind[i]==0) {
                q.push(i);
            }
        }

        
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            ans.push_back(curr);
            for(auto nbr:adj[curr]){
                ind[nbr]--;
                if(ind[nbr]==0) q.push(nbr);
            }
        }

        if(ans.size()==n) return ans;
        return {};
    }
};