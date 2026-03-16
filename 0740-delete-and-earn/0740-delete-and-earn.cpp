class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(i>n-1) return 0;

        if(dp[i]!=-1) return dp[i];
        int j=i+1;
        int s=nums[i];
        while(j<n && nums[j]==nums[i]){
            s+=nums[j];
            j++;
        } 
        int k=j;

        while(j<n && nums[j]==nums[i]+1) j++; 

        int op1=s+f(j,nums,dp);
        int op2=f(k,nums,dp);

        return dp[i]=max(op1,op2);


    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        sort(nums.begin(),nums.end());

        return f(0,nums,dp);
    }
};