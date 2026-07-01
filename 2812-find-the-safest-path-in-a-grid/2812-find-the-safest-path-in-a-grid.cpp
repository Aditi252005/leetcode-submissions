class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        
        queue<tuple<int,int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                if(grid[i][j]) {q.push({0,i,j});grid[i][j]=0;}
                else grid[i][j]=INT_MAX;
            }
        }

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        while(!q.empty()){
            auto [d,i,j]=q.front();
            q.pop();

            if(grid[i][j]<d) continue;

            for(int k=0;k<4;k++){
                int ni=i+dr[k];
                int nj=j+dc[k];

                if(ni>=0 && ni<n && nj>=0 && nj<n){
                    if(grid[ni][nj]>d+1) {
                        grid[ni][nj]=d+1;
                        q.push({d+1,ni,nj});
                    }
                }
            }
        }
       
        priority_queue<tuple<int,int,int>> pq;
        pq.push({grid[0][0],0,0});
       
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;

        while(!pq.empty()){
            auto [v,i,j]=pq.top();
            pq.pop();

            if(i==n-1 && j==n-1) return v;

            for(int k=0;k<4;k++){
                int ni=i+dr[k];
                int nj=j+dc[k];

                if(ni>=0 && ni<n && nj>=0 && nj<n){
                    if(!vis[ni][nj]) {
                        vis[ni][nj]=1;
                        pq.push({min(v,grid[ni][nj]),ni,nj});
                    }
                }
            }
        }
        return 0;
    }
};