class Solution {
public:
    int f(int i,int amt,vector<int>&coins,vector<vector<int>>&dp){
        int n=coins.size();
        if(amt==0) return 0;
        if(i==n || amt<0) return 1e5;
        if(dp[i][amt]!=-1) return dp[i][amt];

        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans, 1+ f(j,amt-coins[j],coins,dp));
        }
        return dp[i][amt]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        int ans= f(0,amount,coins,dp);
        return ans>1e4?-1:ans;
    }
};