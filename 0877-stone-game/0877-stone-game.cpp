class Solution {
public:
    int f(vector<int>&piles,bool turn,int i,int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(turn){
            int op1=piles[i]+f(piles,false,i+1,j,dp);
            int op2=piles[j]+f(piles,false,i,j-1,dp);
            return dp[i][j]=max(op1,op2);
        }else{
            int op1=piles[i]+f(piles,true,i+1,j,dp);
            int op2=piles[j]+f(piles,true,i,j-1,dp);
            return dp[i][j]=max(op1,op2);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int tot=accumulate(piles.begin(),piles.end(),0);
        int a=f(piles,true,0,n-1,dp);
        if(a>tot/2) return true;
        return false;

    }
};