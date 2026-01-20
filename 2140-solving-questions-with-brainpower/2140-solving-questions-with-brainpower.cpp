class Solution {
public:
    long long f(vector<vector<int>>&q,int i,vector<long long>&dp){
        int n=q.size();
        if(i>n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        long long take=q[i][0]+f(q,i+q[i][1]+1,dp);
        long long notTake=f(q,i+1,dp);

        return dp[i]=max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,-1);

        return f(questions,0,dp);
    }
};