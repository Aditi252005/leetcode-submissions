class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(i>n-1) return 0;
        if(dp[i]!=INT_MIN) return dp[i]; 

       
            int ans=INT_MIN;
            int a=0;
            for(int j=i;j<min(n,i+3);j++){
                ans=max(ans,a+nums[j]-f(j+1,nums,dp));
                a+=nums[j];
            } 
            return dp[i]=ans;
        
    }
    string stoneGameIII(vector<int>& s) {
        int n=s.size();

        vector<int> dp(n+1,INT_MIN);

        int a=f(0,s,dp);
        if(a>0) return "Alice";
        else if(a==0) return "Tie";
        return "Bob";
    }
};