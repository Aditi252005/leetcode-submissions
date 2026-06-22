class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int n=grid1.size();
        int m=grid1[0].size();

        if(i<0 || j<0 || i>n-1 || j>m-1 || !grid2[i][j]) return;
        grid2[i][j]=0;

        dfs(i+1,j,grid1,grid2);
        dfs(i,j+1,grid1,grid2);
        dfs(i-1,j,grid1,grid2);
        dfs(i,j-1,grid1,grid2);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] && !grid1[i][j]){
                    dfs(i,j,grid1,grid2);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]){
                    dfs(i,j,grid1,grid2);
                    ans++;
                }
            }
        }
        return ans;
    }
};