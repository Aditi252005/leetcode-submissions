class Solution {
public:
    int minFlips(string s) {
        int n=s.length();
        int z=0,o=0;
        int ans=n;

        for(int i=0;i<n;i++){
            if(s[i]=='0') z++;
            else o++;
        }

        //1. same
        ans=min({z,o});

        //2. 1....1
        if(n>1){
            int c=0;
            if(s[0]=='0') c++;
            if(s[n-1]=='0') c++;
            for(int i=1;i<n-1;i++) if(s[i]=='1') c++;

            ans=min(ans,c);

        } 

        //3. 00..1..00
        ans=min({ans,abs(o-1)});

        return ans;
    }
};