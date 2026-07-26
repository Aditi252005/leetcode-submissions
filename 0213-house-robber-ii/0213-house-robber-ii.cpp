class Solution {
public:
    int f(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        return dp[i]=max(nums[i]+f(i+2,n,nums,dp),f(i+1,n,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        return max(f(0,n-1,nums,dp1),f(1,n,nums,dp2));
    }
};