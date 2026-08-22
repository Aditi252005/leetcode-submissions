class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int s=0;
        int p=1;

        while(n){
            s+=n%10;
            p*=n%10;
            n=n/10;
        }
        return num%(s+p)==0;
    }
};