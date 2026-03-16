class Solution {
public:
    int f(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>n) return 0;
        if(i==n) return nums[i];
        if(dp[i]!=-1) return dp[i];

        int take=nums[i]+f(i+2,n,nums,dp);
        int notTake=f(i+1,n,nums,dp);

        return dp[i]= max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(f(0,n-2,nums,dp1),f(1,n-1,nums,dp2));
    }
};