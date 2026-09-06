class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> changed(n,vector<int>(m,0));

        vector<int> dr={-1,-1,-1,0,1,1,1,0};
        vector<int> dc={-1,0,1,1,1,0,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(int k=0;k<8;k++){
                    int ni=i+dr[k];
                    int nj=j+dc[k];
                    if(ni<0 || nj<0 || ni>n-1 || nj>m-1) continue;
                    if(board[ni][nj]==1) count++;
                }

                if(board[i][j] && (count<2 || count>3)) changed[i][j]=0;
                else if(board[i][j] && (count==2 || count==3)) changed[i][j]=1;
                else if(!board[i][j] && count==3) changed[i][j]=1;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=changed[i][j];
            }
        }
    }
};