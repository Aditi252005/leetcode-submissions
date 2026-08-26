class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();

        int count=0;
        int i=0;
        int j=0;
        string ans(n,'1');
        bool check=false;

        while(j<n){
            if(s[j]=='1') count++;

            while(i<=j && count>=k){
                check=true;
                if(j-i+1==ans.length()){
                    ans=min(ans,s.substr(i,j-i+1));
                }
                else if(j-i+1<ans.length()) ans=s.substr(i,j-i+1);

                if(s[i]=='1') count--;
                i++;
            }

            j++;
        }

        return check?ans:"";
    }
};