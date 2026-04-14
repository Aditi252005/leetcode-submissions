class Solution {
public:
    long long f(int i,int j,int k,vector<int>&r,vector<vector<int>>&fac,vector<vector<vector<long long>>>&dp){
        int n=r.size();
        int m=fac.size();
        if(j>m-1) return ((i < n) ? 1e10 : 0);
        if(i>n-1) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        long long op1=1e18,op2=1e18;
        if(k>0) op1=abs(r[i]-fac[j][0])+f(i+1,j,k-1,r,fac,dp); 
        if(j<m-1) op2=f(i,j+1,fac[j+1][1],r,fac,dp);

        return dp[i][j][k]=min(op1,op2);      

    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n=robot.size();
        int m=factory.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>> (m,vector<long long>(101,-1)));

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        return f(0,0,factory[0][1],robot,factory,dp);
    }
};