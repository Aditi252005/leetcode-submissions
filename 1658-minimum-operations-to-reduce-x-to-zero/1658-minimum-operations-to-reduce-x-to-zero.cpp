class Solution {
public:
    //correct but mle
    // int f(int i,int j,vector<int>&nums,int x,vector<vector<int>>&dp){
    //     int n=nums.size();
    //     if(x==0) return 0;
    //     if(x<0 || i>j) return 1e5;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int op1= 1+f(i+1,j,nums,x-nums[i],dp);
    //     int op2= 1+f(i,j-1,nums,x-nums[j],dp);
    //     return dp[i][j]=min(op1,op2);
    // }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        //vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        //int ans=f(0,n-1,nums,x,dp);
        //return ans>=1e5?-1:ans;
        unordered_map<int,int> mp;
        int s=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(s>x) break;
            if(s==x) ans=min(ans,i+1);
            mp[s]=i+1;
        }

        s=0;
        for(int i=n-1;i>=0;i--){
            s+=nums[i];
            if(s>x) break;
            if(mp.find(x-s)!=mp.end() && mp[x-s]<i) ans=min(ans,mp[x-s]+n-i);
            if(s==x) ans=min(ans,n-i);
        }
        return ans==INT_MAX?-1:ans;

    }
};