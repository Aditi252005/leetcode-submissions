class Solution {
public:
    pair<long long,int> f(int i,vector<int>& nums,vector<pair<long long,int>>&dp){
        int n=nums.size();
        if(i>=n-1) return {0,0};
        if(dp[i].first!=-1) return dp[i]; 

        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
            auto op1=f(i+2,nums,dp);
            op1.second++;
           return dp[i]=op1;
        } 
        else{
            int t=max(0,max(nums[i-1],nums[i+1])+1-nums[i]);
           auto op1=f(i+2,nums,dp);
           op1.second++;
           auto op2=f(i+1,nums,dp);

            if(op1.second==op2.second) return dp[i]={min(t+op1.first,op2.first),op1.second};
          if(op1.second>op2.second) return dp[i]={t+op1.first,op1.second};
          return dp[i]=op2;

        }
            
    }
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();

        vector<pair<long long,int>> dp(n);
        for(int i=0;i<n;i++) dp[i].first=-1;
        return f(1,nums,dp).first;
        
    }
};