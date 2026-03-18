class Solution {
public:
    int f(int i,int j,string& s,vector<vector<int>>&dp){
        int n=s.length();
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]) return dp[i][j]=2+f(i+1,j-1,s,dp);
        return dp[i][j]=INT_MIN;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        string ans;
        int lmax=1;

        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(s[i]==s[j]){
                    int l=f(i,j,s,dp);
                    //cout<<i<<j<<l<<endl;
                    if(l>=lmax){
                        lmax=l;
                        //cout<<s.substr(i,l)<<endl;
                        ans=s.substr(i,l);
                    }
                }
               
            }
        }
        return ans;
    }
};