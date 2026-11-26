class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int i=10;
        bool a=true;

        while(n>0){
            if(n<i) break;
            n-=i;
            i--;
            a=!a;
        }
        return !a;
    }
};