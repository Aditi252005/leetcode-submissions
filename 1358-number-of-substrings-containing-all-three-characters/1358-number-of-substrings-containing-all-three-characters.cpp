class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();

        map<char,int> mp;
        int j=0;
        int i=0;
        int count=0;
        while(j<n){
            mp[s[j]]++;

            while(i<j && mp['a']>0 && mp['b']>0 && mp['c']>0){
                count=count+(n-j);
                mp[s[i]]--;
                i++;
            }

            j++;
        }
        return count;
    }
};