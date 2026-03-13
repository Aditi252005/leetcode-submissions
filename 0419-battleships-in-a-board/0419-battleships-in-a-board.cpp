class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    queue<pair<int,int>> q;
                    ans++;
                    q.push({i,j});
                    while(!q.empty()){
                        int a=q.front().first;
                        int b=q.front().second;
                        q.pop();
                        board[a][b]='.';

                        if(b+1<m && board[a][b+1]=='X')q.push({a,b+1});

                        else if(a+1<n && board[a+1][b]=='X') q.push({a+1,b});

                        
                    }
                }
            }
        }

        return ans;
    }
};