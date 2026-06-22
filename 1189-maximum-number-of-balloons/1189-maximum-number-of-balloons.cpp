class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.length();
        map<char,int> mp;
        mp['b']=0;
        mp['a']=0;
        mp['l']=0;
        mp['o']=0;
        mp['n']=0;
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            if(mp.find(text[i])!=mp.end()){
                mp[text[i]]++;
            }
        }

        for(auto it:mp){
            if(it.first=='l' || it.first=='o') ans=min(ans,it.second/2);
            else ans=min(ans,it.second);
        }

        return ans;
    }
};