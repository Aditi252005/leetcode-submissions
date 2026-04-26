class Solution {
public:
    bool f(int i,int j,int pi,int pj,vector<vector<char>>&grid,vector<vector<bool>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=true;

        int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        char c=grid[i][j];
        for(int k=0;k<4;k++){
            int ni=i+d[k][0];
            int nj=j+d[k][1];

            if(ni<0 || nj<0 || ni>n-1 || nj>m-1 || grid[ni][nj]!=c) continue;

            if(!vis[ni][nj]){
                if(f(ni, nj, i, j, grid, vis)) return true;
            }
            else if(ni != pi || nj != pj){
                return true;
            }
        }

       
        return false; 

        
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(f(i,j,-1,-1,grid,vis)) return true;
                }
            }
        }
        return false;
    }
};