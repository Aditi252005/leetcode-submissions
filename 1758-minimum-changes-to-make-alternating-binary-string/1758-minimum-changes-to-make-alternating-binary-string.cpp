class Solution {
public:
    int f(string& s,int parity){
        int n=s.length();
        char check;
        if(parity==1) check='1';
        else check='0';

        int op=0;        
        for(int i=0;i<n;i++){
            if(s[i]!=check) op++;
            if(check=='1') check='0';
            else check='1';
        }
       
        return op;
    }
    int minOperations(string s) {
        int n=s.length();
        int op1=f(s,1);
        int op2=f(s,0);

        return min(op1,op2);
    }
};