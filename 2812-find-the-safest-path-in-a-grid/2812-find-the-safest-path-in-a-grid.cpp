class Solution {
public:
    bool check(vector<vector<int>>&grid,int v){
        int n=grid.size();
        if(grid[0][0]<v || grid[n-1][n-1]<v) return false;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(n,0));

        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();

            if(i==n-1 && j==n-1) return true;
            if(grid[i][j]<v || vis[i][j]) continue;
            vis[i][j]=1;

            for(int k=0;k<4;k++){
                int ni=i+dr[k];
                int nj=j+dc[k];
                if(ni>=0 && ni<n && nj>=0 && nj<n && !vis[ni][nj]){
                    q.push({ni,nj});
                }
            }
        }
        return false;
    }
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
       
        int ans=0;
        int lo=0;
        int hi=2*n;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;

            if(check(grid,mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid;
        }
        return ans;
    }
};