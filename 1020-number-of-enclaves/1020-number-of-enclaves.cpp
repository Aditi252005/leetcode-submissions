class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || !grid[i][j]) return;

        grid[i][j]=0;

        dfs(i+1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j-1,grid,vis);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1 && grid[i][j]){
                   dfs(i,j,grid,vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                  // dfs(i,j,grid,vis);
                   ans++;
                }
            }
        }
        return ans;
    }
};