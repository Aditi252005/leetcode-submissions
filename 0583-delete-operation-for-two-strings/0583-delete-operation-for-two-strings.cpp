class Solution {
public:
    int f(int i,int j,string&w1,string&w2,vector<vector<int>>&dp){
        int n=w1.length();
        int m=w2.length();
        if(i>n-1) return m-j;
        if(j>m-1) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];

        if(w1[i]==w2[j]) return dp[i][j]=f(i+1,j+1,w1,w2,dp);

        return dp[i][j]= 1+ min(f(i,j+1,w1,w2,dp),f(i+1,j,w1,w2,dp));

    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(0,0,word1,word2,dp);
    }
};