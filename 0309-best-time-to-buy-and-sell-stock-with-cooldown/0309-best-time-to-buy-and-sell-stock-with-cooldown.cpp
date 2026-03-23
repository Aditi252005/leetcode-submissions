class Solution {
public:
    int f(int i,int k,vector<int>&p,vector<vector<int>>&dp){
        int n=p.size();
        if(i>n-1) return 0;
        if(dp[i][k]!=-1) return dp[i][k];

        int op1=0;
        if(!k) op1=-p[i]+f(i+1,1,p,dp);
        else op1=p[i]+f(i+2,0,p,dp);

        int op2=f(i+1,k,p,dp);

        return dp[i][k]=max(op1,op2);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        return f(0,0,prices,dp);
    }
};