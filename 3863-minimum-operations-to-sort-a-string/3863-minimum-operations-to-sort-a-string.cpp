class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        string isSorted=s;
        sort(isSorted.begin(),isSorted.end());
        char mx=isSorted[n-1];
        char mn=isSorted[0];

        if(s==isSorted) return 0;

        if(s[n-1]==mx || s[0]==mn) return 1;

        if(s[0]==mx && n==2) return -1;

        if(s[n-1]==mn && s[0]==mx){
            for(int i=1;i<n-1;i++) if(s[i]==mn || s[i]==mx) return 2;
            return 3;
        } 

        return 2;


    }
};