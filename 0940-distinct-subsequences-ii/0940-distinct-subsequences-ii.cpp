class Solution {
public:
    const int mod=1e9+7;
    int f(int i,string&s,vector<int>&dp){
        int n=s.length();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans=0;
        vector<bool> vis(26,0);
        for(int j=i;j<n;j++){
            if(vis[s[j]-'a']) continue;
            vis[s[j]-'a']=1;
            ans=(ans%mod+1+f(j+1,s,dp)%mod)%mod;
        }
        return dp[i]=ans;
    }
    int distinctSubseqII(string s) {
        int n=s.length();
        vector<int> dp(n+1,-1);

        return f(0,s,dp);
    }
};