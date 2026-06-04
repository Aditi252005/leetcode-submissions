class Solution {
public:
    double myPow(double x, int n) {
        long long i=n;
        if(i<0){
            x=1/x;
            i=-i;
        }

        double ans=1;

        while(i){
            if(i&1) ans*=x;
            x=x*x;
            i>>=1;
        }
        return ans;
    }
};