class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        map<char,int> mp;

        int i=0;
        int j=0;
        int maxl=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                i=max(i,mp[s[j]]+1);
            }

            maxl=max(maxl,j-i+1);
            mp[s[j]]=j;
            j++;
        }
        return maxl;
    }
};