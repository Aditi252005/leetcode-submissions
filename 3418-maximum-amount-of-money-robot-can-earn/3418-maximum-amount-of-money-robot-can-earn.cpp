class Solution {
public:
    int f(int i,int j,vector<vector<int>>&coins,int k,vector<vector<vector<int>>>& dp){
        int n=coins.size();
        int m=coins[0].size();
        if(i>n-1 || j>m-1) return -1e9;
        if(i==n-1 && j==m-1){
            if(k>=1 && coins[i][j]<0) return 0;
            return coins[i][j];
        }
        if(dp[i][j][k]!=-1e9) return dp[i][j][k];


        if(coins[i][j]>=0){
            int op1=coins[i][j]+f(i+1,j,coins,k,dp);
            int op2=coins[i][j]+f(i,j+1,coins,k,dp);
            return dp[i][j][k]=max(op1,op2);
        }else{
            if(k>=1){
                int op1=f(i+1,j,coins,k-1,dp);
                int op2=f(i,j+1,coins,k-1,dp);
                int op3=coins[i][j]+f(i+1,j,coins,k,dp);
                int op4=coins[i][j]+f(i,j+1,coins,k,dp);
                return dp[i][j][k]=max({op1,op2,op3,op4});
            }
            else{
                int op1=coins[i][j]+f(i+1,j,coins,k,dp);
                int op2=coins[i][j]+f(i,j+1,coins,k,dp);
                return dp[i][j][k]=max(op1,op2);
            }
        }
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,-1e9)));

        return f(0,0,coins,2,dp);

    }
};