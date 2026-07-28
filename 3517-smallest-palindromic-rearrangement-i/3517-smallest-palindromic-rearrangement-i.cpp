class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();

        vector<int> v(26,0);
        string ans(n,' ');
        for(auto ch:s){
            v[ch-'a']++;
        }
        
        int j=0;
        for(int i=0;i<26;i++){
            while(v[i]){
                if(v[i]%2) {ans[n/2]='a'+i;v[i]--;}
                else{
                    ans[j]='a'+i;
                    ans[n-j-1]='a'+i;
                    j++;
                    v[i]-=2;
                }
            }
        }
        return ans;
    }
};