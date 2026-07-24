class Solution {
public:
    int f(int i,int t,int target,vector<int>&nums,vector<map<int,int>>&dp){
        int n=nums.size();
        if(i==n) return t==target;
        if(dp[i].count(t)) return dp[i][t]; 

        int op1= f(i+1,t+nums[i],target,nums,dp);
        int op2= f(i+1,t-nums[i],target,nums,dp);

        return dp[i][t]=op1+op2; 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<map<int,int>> dp(n+1);

        return f(0,0,target,nums,dp);
    }
};