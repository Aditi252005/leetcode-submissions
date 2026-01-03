class Solution {
public:
    const int mod=1e9+7;
    int dp[5001][4][4][4];
    int f(int i,int p1,int p2,int p3,int n){
        if(i==n) return 1;
        if(dp[i][p1][p2][p3]!=-1) return dp[i][p1][p2][p3];

        int ans=0;
        for(int col1=1;col1<=3;col1++){
            if(col1==p1) continue;
            for(int col2=1;col2<=3;col2++){
                if(col2==p2 || col2==col1) continue;
                for(int col3=1;col3<=3;col3++){
                    if(col3==p3 || col3==col2) continue;
                    ans=(ans%mod+ f(i+1,col1,col2,col3,n)%mod)%mod;
                }
            }
        }
        return dp[i][p1][p2][p3]=ans;
    }
    int numOfWays(int n) {
       
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,0,n);
    }
};
