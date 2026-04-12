class Solution {
public:
    int d(int a,int b,string& s){
        if(a==26 || b==26) return 0;
        int x1=a/6;
        int y1=a%6;
        int x2=b/6;
        int y2=b%6;
        return abs(x1-x2)+abs(y1-y2);
    }
    int f(int i,int f1,int f2,string&s,vector<vector<vector<int>>>& dp){
        int n=s.length();
        if(i>n-1) return 0;
        if(dp[i][f1][f2]!=-1) return dp[i][f1][f2];

        int curr=s[i]-'A';
        int op1=d(curr,f1,s)+f(i+1,curr,f2,s,dp);
        int op2=d(curr,f2,s)+f(i+1,f1,curr,s,dp);

        return dp[i][f1][f2]=min(op1,op2);
    }
    int minimumDistance(string word) {
        int n=word.length();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(27,vector<int>(27,-1)));

        return f(0,26,26,word,dp);
    }
};