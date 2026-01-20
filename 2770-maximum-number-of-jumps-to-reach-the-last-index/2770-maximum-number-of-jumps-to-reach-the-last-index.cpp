class Solution {
public:
    int f(vector<int>&nums,int i,int target,vector<int>&dp){
        int n=nums.size();
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        
       int ans=INT_MIN;

       for(int j=i+1;j<n;j++){
        if(abs(nums[j]-nums[i])<=target) ans=max(ans,1+f(nums,j,target,dp));
       }
       return dp[i]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n+1,-1);

        int ans= f(nums,0,target,dp);
       
        if(ans>0) return ans;
        return -1;
    }
};