class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        

        vector<int> v(26,0);
        for(auto ch:word){
           v[ch-'a']++;
        }
        sort(v.begin(),v.end());

        int ans=0;
        for(int i=v.size()-1;i>=0;i--){
            int f=v[i];
            int j=v.size()-i-1;
            ans+=f*((j/8)+1);
        }
        return ans;
    }
};