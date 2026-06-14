class Solution {
public:
    bool checkGoodInteger(int n) {
        long long d=0;
        while(n){
            int r=n%10;
            d+=(r*(r-1));
            n=n/10;
        }
        if(d<50) return false;
        return true;
    }
};