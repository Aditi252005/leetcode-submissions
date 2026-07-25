class Solution {
public:
    int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1 && j==m-1 && !grid[i][j]) return 1;
        if(i>n-1 || j>m-1 || grid[i][j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]= f(i+1,j,grid,dp)+f(i,j+1,grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n=o.size();
        int m=o[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(0,0,o,dp);
    }
};