class Solution {
public:
    int f(int i,int k,vector<int>&arr,vector<int>&dp){
        int n=arr.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans=0;
        int maxi=arr[i];
        for(int j=i;j<min(n,i+k);j++){
            maxi=max(maxi,arr[j]);
            int l=j-i+1;
            ans=max(ans, maxi*l+ f(j+1,k,arr,dp));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);

        return f(0,k,arr,dp);
    }
};