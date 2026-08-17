class Solution {
public:
    int f(int start,int i,int last,vector<int>&s,int ts, vector<vector<int>>&dp){
        if(i==last) return 0;
        if(dp[i][last]!=-1) return dp[i][last];

        int ans=0;
        int curs=0;
        for(int j=start;j<last;j++){
            curs+=s[j];
            int rems= ts-curs;

            if(curs==rems){
                ans=max(ans, rems+ f(j+1,j+1,last,s,ts-curs,dp));
                ans=max(ans, curs+ f(start,start,j,s,ts-rems,dp));
            }
            else if(curs>rems){
                ans=max(ans, rems+ f(j+1,j+1,last,s,ts-curs,dp));
            }else{
                ans=max(ans, curs+ f(start,start,j,s,ts-rems,dp));
            }
        }

        return dp[i][last]=ans;
    }
    int stoneGameV(vector<int>& s) {
        int n=s.size();

        int ts=accumulate(s.begin(),s.end(),0);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return f(0,0,n,s,ts,dp);
    }
};