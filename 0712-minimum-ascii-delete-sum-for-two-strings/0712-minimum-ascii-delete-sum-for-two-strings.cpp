class Solution {
public:
    int f(string&s1,string&s2,int i,int j,vector<vector<int>>&dp){
        int n=s1.length();
        int m=s2.length();
        if(i>n-1 && j<=m-1){
            return accumulate(s2.begin()+j,s2.end(),0);
        }
        if(i<=n-1 && j>m-1){
            return accumulate(s1.begin()+i,s1.end(),0);
        }
        if(i==n-1 && j==m-1){
            if(s1[i]==s2[j]) return 0;
            else return s1[i]+s2[j];
        }

        if(dp[i][j]!=-1) return dp[i][j];

        
        if(s1[i]==s2[j]) return dp[i][j]=f(s1,s2,i+1,j+1,dp);
        return dp[i][j]=min(s1[i]+f(s1,s2,i+1,j,dp),s2[j]+f(s1,s2,i,j+1,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return f(s1,s2,0,0,dp);
    }
};