class Solution {
public:
    long long f(int i,vector<int>&nums,vector<int>&c,vector<long long>&dp){
        int n=nums.size();
        if(i>n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        long long take=0;
        if(i+1<n && c[i+1]==c[i]) take=nums[i]+f(i+2,nums,c,dp);
        else take=nums[i]+f(i+1,nums,c,dp);

        long long skip=f(i+1,nums,c,dp);

        return dp[i]=max(take,skip);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<long long> dp(n,-1);

        return f(0,nums,colors,dp);
    }
};