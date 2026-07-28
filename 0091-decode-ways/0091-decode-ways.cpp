class Solution {
public:
    int f(int i,string&s,vector<int>&dp){
        int n=s.length();
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];

        int temp=0;
        int ans=0;
        for(int j=i;j<n;j++){
            temp= temp*10 + (s[j]-'0');
            if(temp<=26) ans= ans+ f(j+1,s,dp);
            else break;            
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,-1);

        return f(0,s,dp);
    }
};