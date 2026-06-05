class Solution {
public:
    bool f(int i,int j,int k,vector<vector<char>>& board,string word,vector<vector<int>>& vis){
        int n=board.size();
        int m=board[0].size();
        if(i>n-1 || j>m-1 || i<0 || j<0 || vis[i][j] || word[k]!=board[i][j]) return false;

        if(k==word.length()-1){
            if(word[k]==board[i][j]) return true;
        }
        
        vis[i][j]=1;

        bool ans= f(i-1,j,k+1,board,word,vis)
            || f(i,j-1,k+1,board,word,vis)
            || f(i+1,j,k+1,board,word,vis)
            || f(i,j+1,k+1,board,word,vis);

        vis[i][j]=0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(f(i,j,0,board,word,vis)) return true;
                }
            }
        }

        return false;
    }
};