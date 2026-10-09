class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(i>n-1) return 1e5;
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        int minj=1e5;
        for(int j=1;j<=nums[i];j++){
            minj=min(minj,1+f(i+j,nums,dp));
        }
        return dp[i]=minj;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);

        return f(0,nums,dp);
    }
};