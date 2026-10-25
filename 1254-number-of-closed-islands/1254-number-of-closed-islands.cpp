class Solution {
public:
    bool f(int i,int j,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1) return false;
        if(grid[i][j]==1 || grid[i][j]==-1) return true;
        grid[i][j]=-1;

        bool t=f(i-1,j,grid);
        bool d=f(i+1,j,grid);
        bool r=f(i,j+1,grid);
        bool l=f(i,j-1,grid);

        return t&&d&&r&&l;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) {
                    if(f(i,j,grid)) count++;
                }
            }
        }
        return count;
    }
};