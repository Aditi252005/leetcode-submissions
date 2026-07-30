class Solution {
public:
    bool isPali(int i,int j,string&s,vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        while(i<j){
            if(s[i]!=s[j]) return dp[i][j]=false;
            i++;
            j--;
        }
        return dp[i][j]=true;
    }
    int f(int i,int j,string&s,vector<vector<int>>&dp1,vector<vector<int>>&dp2){
        int n=s.length();
        if(i==n || j==n) return 0;
        if(dp2[i][j]!=-1) return dp2[i][j];

        int ans=INT_MAX;
        for(int k=j;k<n;k++){
            if(isPali(i,k,s,dp1)){
                ans=min(ans,1+f(k+1,k+1,s,dp1,dp2));
            }
        }
        return dp2[i][j]=ans;
    }
    int minCut(string s) {
        int n=s.length();
        vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));
        vector<vector<int>> dp2(n+1,vector<int>(n+1,-1));

        return f(0,0,s,dp1,dp2)-1;
    }
};