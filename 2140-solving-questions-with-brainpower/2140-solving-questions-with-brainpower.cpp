class Solution {
public:
    long long f(int i,vector<vector<int>>&q,vector<long long>&dp){
        int n=q.size();
        if(i>n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        long long take=q[i][0]+f(i+q[i][1]+1,q,dp);
        long long skip=f(i+1,q,dp);

        return dp[i]=max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return f(0,questions,dp);
    }
};