class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.length();
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L') x--;
            else if(moves[i]=='R')x++;
            else if(moves[i]=='U') y++;
            else y--;
        }

        if(x==0 && y==0) return true;
        return false;
    }
};