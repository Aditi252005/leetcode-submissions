class Solution {
public:
    bool valid(int i,int j,char ch,vector<vector<char>>& board){
        for(int b=0;b<9;b++) if(board[i][b]==ch) return false;
        for(int a=0;a<9;a++) if(board[a][j]==ch) return false;

        int is=3*(i/3);
        int js=3*(j/3);
        for(int a=is;a<is+3;a++){
            for(int b=js;b<js+3;b++){
                if(board[a][b]==ch) return false;
            }
        }
        return true;
    }
    bool f(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(valid(i,j,ch,board)){
                            board[i][j]=ch;
                            if(f(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};