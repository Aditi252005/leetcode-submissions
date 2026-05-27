class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();
        vector<int> v(26,0);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z') mp[word[i]-'a']++;
        }

        int count=0;
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z') {
                v[word[i]-'a']++;
            }else{
                if(mp.find(word[i]-'A')==mp.end()) continue;
                if(v[word[i]-'A'] && v[word[i]-'A']==mp[word[i]-'A']) {count++;mp[word[i]-'A']=0;}
                else{ mp[word[i]-'A']=0;v[word[i]-'A']=0;}
            }
            cout<<count;
        }
        return count;
    }
};