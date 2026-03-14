class Solution {
public:
    void f(int i,int j,vector<vector<char>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        
        if(i<0 || i>n-1 || j<0 || j>m-1) return;
        if(grid[i][j]=='0' || grid[i][j]=='2') return;

        grid[i][j]='2';

        f(i+1,j,grid);
        f(i,j+1,grid);
        f(i-1,j,grid);
        f(i,j-1,grid);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    f(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};