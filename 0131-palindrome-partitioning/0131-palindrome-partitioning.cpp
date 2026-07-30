class Solution {
public:
    bool isPali(int i,int j,string&s,vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        while(i<j){
            if(s[i]!=s[j]) return dp[i][j]= false;
            i++;
            j--;
        }
        return dp[i][j]=true;
    }
    void f(int i,int j,string&s,vector<string>&v,vector<vector<string>>&ans,vector<vector<int>>&dp){
        int n=s.size();
        if(i==n || j==n) {ans.push_back(v);return;}

        for(int k=j;k<n;k++){
            if(isPali(i,k,s,dp)){
                v.push_back(s.substr(i,k-i+1));
                f(k+1,k+1,s,v,ans,dp);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<string>> ans;
        vector<string> v;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        f(0,0,s,v,ans,dp);
        return ans;
    }
};