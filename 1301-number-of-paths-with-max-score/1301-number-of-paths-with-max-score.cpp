class Solution {
public:
    const int mod=1e9+7;
    int f(int i,int j,vector<string>&board,vector<vector<int>>&dp){
        int n=board.size();
        if(i==0 && j==0) return dp[0][0] = 0;
        if(i<0 || j<0 || board[i][j]=='X') return INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];

        int val=(i==n-1 && j==n-1)?0:board[i][j]-'0';

       return dp[i][j]= val+max({f(i-1,j,board,dp),f(i-1,j-1,board,dp),f(i,j-1,board,dp)});
    }
    int g(int i,int j,vector<string>&board,vector<vector<int>>&w,vector<vector<int>>&dp){
        int n=board.size();
        if(i==0 && j==0) return 1;
        if(i<0 || j<0 || board[i][j]=='X' || dp[i][j]<0) return 0;
        if(w[i][j]!=-1) return w[i][j];

        int val=(i==n-1 && j==n-1)?0:board[i][j]-'0';

        int dr[3]={-1,-1,0};
        int dc[3]={0,-1,-1};
        int ans=0;
        for(int k=0;k<3;k++){
            int ni=i+dr[k];
            int nj=j+dc[k];
            if(ni>=0 && nj>=0 && board[ni][nj]!='X' && dp[ni][nj]>=0){
                if(dp[i][j]==dp[ni][nj]+val){
                    ans= (ans+ g(ni,nj,board,w,dp))%mod;
                }
            }
        }
        return w[i][j]=ans;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int maxs=f(n-1,n-1,board,dp);
        if(maxs<0) return {0,0};

        vector<vector<int>> w(n,vector<int>(n,-1));
        int ways=g(n-1,n-1,board,w,dp);

        return {maxs,ways};
    }
};