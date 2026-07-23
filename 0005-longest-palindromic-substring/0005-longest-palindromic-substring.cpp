class Solution {
public:
    int f(int i,int j,string&s,vector<vector<int>>&dp){
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]) return dp[i][j]=2+f(i+1,j-1,s,dp);
        return INT_MIN;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int maxl=0;
        string ans;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                if(s[i]==s[j]) {
                    int l= f(i,j,s,dp);
                    if(l>maxl) {maxl=l;ans=s.substr(i,l);}
                }
            }
        }
        return ans;
    }
};