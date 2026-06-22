class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,int direc){
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1) return;
        if(board[i][j]=='.') return;

        board[i][j]='.';

        if(direc==1) dfs(i+1,j,board,1);
        else dfs(i,j+1,board,2);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    if(i+1<n && board[i+1][j]=='X') dfs(i,j,board,1);
                    else dfs(i,j,board,2);
                    ans++;
                }
            }
        }
        return ans;
    }
};