class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int p=1;
            int a=n;
            while(a){
                p=p*(a%10);
                a=a/10;
            }
            if(p%t==0) return n;
            n++;
        }
        return 0;
    }
};