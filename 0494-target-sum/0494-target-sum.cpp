class Solution {
public:
    int f(int i,int s,vector<int>&nums,int t,vector<vector<int>>&dp){
        int n=nums.size();
        if(i==n) return s==t;
        
        if(dp[i][s+1000]!=-1) return dp[i][s+1000];

        int op1= f(i+1,s+nums[i],nums,t,dp);
        int op2= f(i+1,s-nums[i],nums,t,dp);

        return dp[i][s+1000]=op1+op2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2001,-1));

        return f(0,0,nums,target,dp);
    }
};