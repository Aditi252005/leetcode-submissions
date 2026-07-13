class Solution {
public:
    int maxRepeating(string s, string w) {
        int n=s.length();
        int m=w.length();

        int k=1;
        string t=w;
        while(true){
            if(s.find(t)!=string::npos){
                k++;
                t+=w;
            }else break;
        }
       
        return k-1;
    }
};