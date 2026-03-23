class Solution {
public:
    long long f(int i,int t,int k,vector<int>&p,vector<vector<vector<long long>>>&dp){
        int n=p.size();
        if(t<0) return INT_MIN;
        if(i>n-1){
            if(t>=0 && k==0) return 0;
            return INT_MIN;
        } 
        if(dp[i][t][k]!=-1) return dp[i][t][k];

        long long op1=LLONG_MIN;
        if(k==0){
            op1=max(-p[i]+f(i+1,t,1,p,dp),p[i]+f(i+1,t,2,p,dp));
        }else if(k==1){
            op1=p[i]+f(i+1,t-1,0,p,dp);
        }else if(k==2){
            op1=-p[i]+f(i+1,t-1,0,p,dp);
        }

        long long op2=f(i+1,t,k,p,dp);

        return dp[i][t][k]=max(op1,op2);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(k+1,vector<long long>(3,-1)));

        return f(0,k,0,prices,dp);
    }
};