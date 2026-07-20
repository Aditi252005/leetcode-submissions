class Solution {
public:
    int maxe(int i,int j,vector<int>&arr){
        int n=arr.size();
        int maxi=0;
        for(int k=i;k<=min(n-1,j);k++){ 
            maxi=max(maxi,arr[k]);
        }
        return maxi;
    }
    int f(int i,int k,vector<int>&arr,vector<int>&dp){
        int n=arr.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans=0;
        for(int j=i;j<min(n,i+k);j++){
            int maxi=maxe(i,j,arr)*(j-i+1);
            ans=max(ans, maxi+ f(j+1,k,arr,dp));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);

        return f(0,k,arr,dp);
    }
};