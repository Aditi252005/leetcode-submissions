class Solution {
public:
    bool isPali(int i,int j,string&s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.length();

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                if(isPali(i,j,s)) ans++;
            }
        }
        return ans;
    }
};