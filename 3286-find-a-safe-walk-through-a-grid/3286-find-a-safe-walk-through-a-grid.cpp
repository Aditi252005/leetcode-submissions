class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();

        priority_queue<tuple<int,int,int>> pq;
        pq.push({health,0,0});

        vector<vector<int>> dis(n,vector<int>(m,0));
        dis[0][0]=health;

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        while(!pq.empty()){
            auto [h,i,j]=pq.top();
            pq.pop();

            if(i==n-1 && j==m-1){
                h=h-grid[i][j];
                if(h>0) return true;
                return false;
            }
            if(dis[i][j]>h || h<0) continue;

            for(int k=0;k<4;k++){
                int ni=i+dr[k];
                int nj=j+dc[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    if(dis[ni][nj]<h-grid[i][j]){
                        dis[ni][nj]=h-grid[i][j];
                        pq.push({dis[ni][nj],ni,nj});
                    }
                }
            }
        }
        return false;
    }
};