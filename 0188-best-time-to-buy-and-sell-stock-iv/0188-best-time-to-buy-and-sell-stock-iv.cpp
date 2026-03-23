class Solution {
public:
    int f(int i,int t,int k,vector<int>&p,vector<vector<vector<int>>>&dp){
        int n=p.size();
        if(i>n-1 || t==0) return 0; 
        if(dp[i][t][k]!=-1) return dp[i][t][k];

        int op1=0,op2=0;
        if(!k) op1=-p[i]+f(i+1,t,1,p,dp);
        else op1=p[i]+f(i+1,t-1,0,p,dp);

        op2=f(i+1,t,k,p,dp);
        return dp[i][t][k]=max(op1,op2);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));

        return f(0,k,0,prices,dp);
    }
};