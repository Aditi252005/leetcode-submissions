class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();

        map<char,int> mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                ans=max(ans,j-i);
                i=max(i,mp[s[j]]+1);
            }
            mp[s[j]]=j;
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};