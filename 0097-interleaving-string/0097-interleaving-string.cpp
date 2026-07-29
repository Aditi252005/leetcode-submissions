class Solution {
public:
    bool f(int i,int j,int k,string&s,string&t,string&u, vector<vector<vector<int>>>&dp){
        int n=s.length();
        int m=t.length();
        int l=u.length();
        if(i==n && j==m && k==l) return true;
        if(k==l && (i<n || j<m)) return false;
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        bool op1=false,op2=false;
        if(s[i]==u[k]) op1= f(i+1,j,k+1,s,t,u,dp);

        if(t[j]==u[k]) op2= f(i,j+1,k+1,s,t,u,dp);

        return dp[i][j][k]= op1||op2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        int l=s3.length();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(l+1,-1)));

        return f(0,0,0,s1,s2,s3,dp);
    }
};