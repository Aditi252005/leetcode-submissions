class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //abcabcbb
        //l=j-i+1;
        //j=0 l=1
        //j=1 l=2
        //j=2 l=3
        //j=3, i=1 

        int n=s.length();
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            while(i<j && mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            int l=j-i+1;
            ans=max(ans,l);
            j++;
        }

        return ans;

    }
};