class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.length();
        int l=0,r=0,s=0;

        for(int i=0;i<n;i++){
            if(moves[i]=='L') l++;
            else if(moves[i]=='R') r++;
            else s++;
        }
        return abs(r-l)+s;
    }
};