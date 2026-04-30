class Solution {
public:
    int f(int i,int j,vector<vector<int>>&grid,int k,vector<vector<vector<int>>>& dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i>n-1 || j>m-1) return INT_MIN;
        int s=grid[i][j],c=(grid[i][j] == 0 ? 0 : 1);
        if(c>k) return INT_MIN;
        if(i==n-1 && j==m-1) return s;
        if (dp[i][j][k]!=-1) return dp[i][j][k];

        int d = f(i + 1, j, grid, k - c, dp);
        int r = f(i, j + 1, grid, k - c, dp);

        int best = INT_MIN;

        if (d != INT_MIN) best = max(best, s + d);

        if (r != INT_MIN) best = max(best, s + r);

        return dp[i][j][k] = best;       
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans = f(0, 0, grid, k, dp);
        return (ans == INT_MIN) ? -1 : ans;
        
        //0 1
        //2 0
    }
};