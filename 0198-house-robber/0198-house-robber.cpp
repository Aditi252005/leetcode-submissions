class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(i>n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        int take=nums[i]+f(i+2,nums,dp);
        int notTake=f(i+1,nums,dp);

        return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int> dp(n,-1);

        return max(f(0,nums,dp),f(1,nums,dp));
    }
};