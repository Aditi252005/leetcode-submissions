class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        vector<int> v(26,0);
        for(auto c:s) v[c-'a']++;

        string ans(n,' ');
        int j=0,k=n-1;
        for(int i=0;i<26;i++){
            while(v[i]){
                if(v[i]%2==0){
                    ans[j]=i+'a';
                    ans[k]=i+'a';
                    v[i]-=2;
                    j++;
                    k--;
                }else{
                    if(v[i]==1) {ans[(j+k)/2]=i+'a';v[i]--;}
                    else{
                        ans[j]=i+'a';
                        ans[k]=i+'a';
                        ans[(j+k)/2]=i+'a';
                        v[i]-=3;
                        j++;
                        k--;
                    }
                }
                // j++;
                // k--;
            }
        }
        return ans;
    }
};