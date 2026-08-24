class Solution {
public:
    int f(int i,vector<int>&p,vector<int>&dp){
        int n=p.size();
        if(i>=n-1) return p[n-1];
        if(dp[i]!=-1e9) return dp[i];

        int take= p[i]-f(i+1,p,dp);
        int skip= f(i+1,p,dp);
    
        return dp[i]=max(take,skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> dp(n+1,-1e9);
        vector<int> pre(n,0);
        pre[0]=stones[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+stones[i];

        return f(1,pre,dp);
    }
};