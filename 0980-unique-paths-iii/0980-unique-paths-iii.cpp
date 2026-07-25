class Solution {
public:
    int ans=0;
    void f(int i,int j,int v,int t,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || vis[i][j] || grid[i][j]==-1) return;

        vis[i][j]=1;
        v++;

        if(grid[i][j]==2) {
            if(v==t) ans++;
            vis[i][j]=0;
            return;
        }

       
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        
        for(int k=0;k<4;k++){
            f(i+dr[k],j+dc[k],v,t,grid,vis);
        }

        vis[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=-1) total++;
            }
        }

        bool found=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {f(i,j,0,total,grid,vis);found=true;break;}
            }
            if(found) break;
        }

        return ans;
    }
};