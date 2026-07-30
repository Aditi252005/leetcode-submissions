class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        map<char,int> mp;
        for(auto ch:word) mp[ch]++;

        int ans=0;
        for(int i=0;i<n;i++){
            if(i<8) ans+=mp[word[i]];
            else if(i<16) ans+=mp[word[i]]*2;
            else if(i<24) ans+=mp[word[i]]*3;
            else ans+=mp[word[i]]*4;
            mp[word[i]]=0;
        }
        return ans;
    }
};