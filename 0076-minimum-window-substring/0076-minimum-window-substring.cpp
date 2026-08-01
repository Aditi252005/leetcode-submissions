class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(n<t.length()) return "";

        s.push_back('*');
        map<char,int> mps,mpt;
        for(auto ch:t) mpt[ch]++;

        int i=0;
        int j=0;
        string ans(n+1,'z');

        while(j<=n){
            mps[s[j]]++;
            bool check=true;
            for(auto it:mpt){
                if(mps[it.first]<it.second){check=false;break;}
            }

            if(check){
                while(i<j && mps[s[i]]>mpt[s[i]]){
                    mps[s[i]]--;
                    i++;
                }
                int l=j-i+1;
                if(l<ans.length()) ans=s.substr(i,j-i+1);
            }
            j++;
        } 

        string a(n+1,'z');
        return ans==a?"":ans;
    }
};