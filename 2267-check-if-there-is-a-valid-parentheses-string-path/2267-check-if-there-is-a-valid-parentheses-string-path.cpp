class Solution {
public:
    bool f(int i,int j,vector<vector<char>>&grid,int count,vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i>n-1 || j>m-1) return false;

        if(grid[i][j]=='(') count++;
        else count--;

        if(count<0) return false;
        if(i==n-1 && j==m-1){
           return count==0;
        }
        if(dp[i][j][count]!=-1) return dp[i][j][count];
       
        
        return dp[i][j][count]= f(i+1,j,grid,count,dp) || f(i,j+1,grid,count,dp);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(n+m,-1)));
        return f(0,0,grid,0,dp);

    }
};