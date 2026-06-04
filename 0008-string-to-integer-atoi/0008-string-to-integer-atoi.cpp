class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int ans=0;

        int i=0;
        bool neg=false;
        while(s[i]==' ') i++;
        if(s[i]=='-') {neg=true;i++;}
        else if(s[i]=='+') i++;

        while(i<n){
            char ch=s[i]-'0';
            if(ch>9 || ch<0) {break;}
            if((long long)ans*10+ch>INT_MAX){
                if(neg) return INT_MIN;
                else return INT_MAX;
            }
            ans=ans*10 + (ch);
            i++;
        }
        if(neg) return -ans;
        return ans;

    }
};