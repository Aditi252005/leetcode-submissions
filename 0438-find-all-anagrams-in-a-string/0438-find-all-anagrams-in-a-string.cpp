class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length();
        int m=p.length();

        map<char,int> mp1,mp2;
        for(int i=0;i<m;i++) mp2[p[i]]++;

        int i=0;
        int j=0;
        vector<int> ans;
        while(j<n){
            mp1[s[j]]++;

            if(j>m-1) {
                mp1[s[i]]--;
                if(mp1[s[i]]==0) mp1.erase(s[i]);
                i++;
            }

            if(mp1==mp2) ans.push_back(i);            
            j++;
        }

        return ans;
    }
};