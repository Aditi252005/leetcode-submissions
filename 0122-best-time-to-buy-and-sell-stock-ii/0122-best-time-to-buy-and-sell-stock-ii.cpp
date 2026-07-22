class Solution {
public:
    int f(int i,int buy,vector<int>&prices,vector<vector<int>>&dp){
        int n=prices.size();
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int op1=0;
        if(buy){
            op1= -prices[i]+ f(i+1,0,prices,dp);
        }
        else{
            op1= prices[i]+ f(i+1,1,prices,dp);
        }
        
        int op2= f(i+1,buy,prices,dp);

        return dp[i][buy]=max(op1,op2);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        return f(0,1,prices,dp);
    }
};