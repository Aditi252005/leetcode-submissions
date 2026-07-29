class Solution {
public:
    bool f(int i,int sum,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(sum==0) return true;
        if(sum<0) return false;
        if(i==n-1) return sum==nums[i];
        if(dp[i][sum]!=-1) return dp[i][sum];

        return dp[i][sum]= f(i+1,sum-nums[i],nums,dp) || f(i+1,sum,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        int totals=accumulate(nums.begin(),nums.end(),0);
        if(totals%2) return false;
        vector<vector<int>> dp(n+1,vector<int>(totals/2 +1,-1));

        return f(0,totals/2,nums,dp);
    }
};