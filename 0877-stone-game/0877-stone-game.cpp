class Solution {
public:
    int f(vector<int>&piles,int i,vector<int>&dp){
        int n=piles.size();
        if(i>n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        int op1=piles[i]+f(piles,i+2,dp);
        int op2=f(piles,i+1,dp);
        return dp[i]=max(op1,op2);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<int> dp(n+1,-1);

        int tot=accumulate(piles.begin(),piles.end(),0);
        int a=f(piles,0,dp);
        if(a>tot/2) return true;
        return false;

    }
};