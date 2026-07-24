class Solution {
public:
    int f(int i,int amt,vector<int>&coins,vector<vector<int>>&dp){
        int n=coins.size();
        if(amt==0) return 1;
        if(i==n || amt<0) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];

        int ans=0;
        for(int j=i;j<n;j++){
            ans+= f(j,amt-coins[j],coins,dp);
        }
        return dp[i][amt]=ans;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        return f(0,amount,coins,dp);
    }
};