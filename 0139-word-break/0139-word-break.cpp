class Solution {
public:
    bool f(int i,string&s,set<string>&dic,vector<int>&dp){
        int n=s.length();
        if(i==n){
             return true;
        }
        if(dp[i]!=-1) return dp[i];

        string temp;
        bool ans=false;
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(dic.find(temp)!=dic.end()) ans=ans || f(j+1,s,dic,dp);
        }

        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& word) {
        int n=s.length();
        int m=word.size();
        set<string> dic(word.begin(),word.end());
        vector<int> dp(n+1,-1);

        return f(0,s,dic,dp);
    }
};