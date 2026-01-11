class Solution {
public:
    int residuePrefixes(string s) {
        int n=s.length();
        map<char,int> mp;

        int count=0,c=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]==1) c++;
            if((i+1)%3==c) count++;
        }
        return count;
    }
};