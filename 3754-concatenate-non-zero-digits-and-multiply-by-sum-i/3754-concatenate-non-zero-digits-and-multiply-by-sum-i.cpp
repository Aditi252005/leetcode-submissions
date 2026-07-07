class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long s=0;
        long long l=1;
        while(n){
            if(n%10!=0) {x=x +(n%10)*l; s=s+n%10; l=l*10;}
            n=n/10;
        }

        return s*x;

    }
};