class Solution {
public:
    bool validDigit(int n, int x) {
        bool check=false;
        while(n>9){
            if(n%10==x) check=true;
            n=n/10;
        }
        if(check && n!=x) return true;
        return false;
    }
};