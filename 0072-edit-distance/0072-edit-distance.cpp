class Solution {
public:
    int f(int i,int j,string& s1,string& s2,vector<vector<int>>&dp){
        int n=s1.length();
        int m=s2.length();
        if(i==n && j<=m) return m-j;
        if(j==m && i<=n) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];

        int op1=0,op2=0,op3=0;
        if(s1[i]!=s2[j]){
            op1=1+f(i,j+1,s1,s2,dp);
            op2=1+f(i+1,j,s1,s2,dp);
            op3=1+f(i+1,j+1,s1,s2,dp);
        }else return dp[i][j]=f(i+1,j+1,s1,s2,dp);

        return dp[i][j]=min({op1,op2,op3});
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return f(0,0,word1,word2,dp);
    }
};