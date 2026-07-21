class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s='1'+s+'1';
        int n=s.length();

        int count=0;
        for(int i=1;i<n-1;i++) if(s[i]=='1') count++;

        int i=0;
        while(i<n && s[i]=='1') {i++;}

        int z1=0;
        int ans=count;
        while(i<n){
           
            while(i<n && s[i]=='0') {i++;z1++;}

            int o=0;
            while(i<n && s[i]=='1') {i++;o++;}
            //if(!o) break;

            int z2=0;
            while(i<n && s[i]=='0') {i++;z2++;}
            if(!z2) break;

            ans=max(ans,z1+count+z2);
            z1=z2;
        }

        return ans;
    }
};