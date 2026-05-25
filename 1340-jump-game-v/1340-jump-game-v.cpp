class Solution {
public:
    int f(int i,vector<int>&arr,int d,vector<int>&dp){
        int n=arr.size();
        if(i<0 || i>n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans=1;
        for(int j=i-1;j>=max(0,i-d);j--){
            if(arr[j]>=arr[i]) break;
            ans=max(ans,1+f(j,arr,d,dp));
        }

        for(int j=i+1;j<=min(n-1,i+d);j++){
            if(arr[j]>=arr[i]) break;
            ans=max(ans,1+f(j,arr,d,dp));
        }

        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> dp(n,-1);

        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,f(i,arr,d,dp));
        }

        return ans;
    }
};