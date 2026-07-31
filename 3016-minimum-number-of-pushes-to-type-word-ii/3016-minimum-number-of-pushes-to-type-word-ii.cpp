class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        map<char,int> mp;
        for(auto ch:word) mp[ch]++;

        vector<pair<int,char>> v;
        for(auto it:mp){
            char ch=it.first;
            int f=it.second;
            v.push_back({f,ch});
        }
        sort(v.begin(),v.end());

        int ans=0;
        for(int i=v.size()-1;i>=0;i--){
            int f=v[i].first;
            int j=v.size()-i-1;
            if(j<8) ans+=f;
            else if(j<16) ans+=f*2;
            else if(j<24) ans+=f*3;
            else ans+=f*4;
        }
        return ans;
    }
};