class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ind(n);
        for(auto it:invocations){
            adj[it[0]].push_back(it[1]);
            ind[it[1]].push_back(it[0]);
        }

        vector<int> susp(n,0);
        queue<int> q;
        q.push(k);
       
        while(!q.empty()){
            int node=q.front();
            q.pop();
            susp[node]=1;

            for(auto nbr:adj[node]){
                if(!susp[nbr]) q.push(nbr);
            }
        }

        bool check=true;
        for(int i=0;i<n;i++){
            if(!susp[i]){
                for(auto nbr:adj[i]){
                    if(susp[nbr]) {check=false;break;}
                }
            }
            if(!check) break;
        }

        

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!check) ans.push_back(i);
            else if(!susp[i]) ans.push_back(i);
        }

        return ans;
    }
};