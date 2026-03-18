class Solution {
public:
    bool check(int i,int j,string s,vector<vector<int>>&dp){
        int n=s.length();
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]!=s[j]) return dp[i][j]=false;
        return dp[i][j]=check(i+1,j-1,s,dp);
        
    }
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && check(i,j,s,dp)) ans+=1; 
            }
        }
        return ans;
    }
};