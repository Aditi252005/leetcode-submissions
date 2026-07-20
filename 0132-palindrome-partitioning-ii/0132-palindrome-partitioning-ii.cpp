class Solution {
public:
    bool check(int i,int j,string&s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,string&s,vector<int>&dp){
        int n=s.length();
        if(i==n || check(i,n-1,s)) return 0;
        if(dp[i]!=-1) return dp[i];

        int mini=1e5;
        for(int j=i;j<n;j++){
            if(check(i,j,s)) mini=min(mini,1+f(j+1,s,dp));
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n+1,-1);

        return f(0,s,dp);
    }
};